#include <lpp.h>
#include <modem.h>
#include <rtcm_generator.h>
#include <arpa/inet.h>
#include <fstream>
#include <getopt.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define UNUSED [[maybe_unused]]
#define SSR 0

static struct option long_options[] = {
    {"host", required_argument, NULL, 'h'},
    {"port", required_argument, NULL, 'p'},
    {"mcc", required_argument, NULL, 'c'},
    {"mnc", required_argument, NULL, 'n'},
    {"cellid", required_argument, NULL, 'i'},
    {"tac", required_argument, NULL, 't'},
    {"msm_type", required_argument, NULL, 'y'},
    {"server_ip", required_argument, NULL, 'k'},
    {"server_port", required_argument, NULL, 'o'},
    {"file_output", required_argument, NULL, 'x'},
    {"serial_port", required_argument, NULL, 'd'},
    {"serial_port_baud_rate", required_argument, NULL, 'r'},
    {"modem_device", required_argument, NULL, 'm'},
    {"modem_baud_rate", required_argument, NULL, 'b'},
    {"ssl", no_argument, NULL, 's'},
    {NULL, 0, NULL, 0},
};

struct Options {
    const char* host;
    int         port;
    bool        ssl;

    long mcc;
    long mnc;
    long tac;
    long cell_id;
    long msm_type;

    const char* server_ip;
    int         server_port;

    const char*  file_output;
    const char*  serial_port;
    long serial_port_baud_rate;
    const char*  modem;
    unsigned int modem_baud_rate;
};

Options parse_arguments(int argc, char* argv[]) {
    Options options{};
    options.host     = "129.192.82.208";
    options.port     = 5431;
    options.ssl      = false;
    options.msm_type = -1;

    options.server_ip   = "127.0.0.1";
    options.server_port = 3000;

    options.mcc     = 310;
    options.mnc     = 260;
    options.tac     = 1;
    options.cell_id = 3;

    options.modem           = NULL;
    options.modem_baud_rate = 9600;

    options.serial_port = "/dev/ttyAMA0";
    options.serial_port_baud_rate = 38400;

    int c;
    int option_index;
    while ((c = getopt_long(argc, argv, "h:p:sc:n:i:t:y:k:o:x:d:r:m:b:", long_options, &option_index)) !=
           -1) {
        switch (c) {
        case 'h': options.host = strdup(optarg); break;
        case 'p': options.port = atoi(optarg); break;
        case 's': options.ssl = true; break;

        case 'c': options.mcc = atoi(optarg); break;
        case 'n': options.mnc = atoi(optarg); break;
        case 'i': options.cell_id = atoi(optarg); break;
        case 't': options.tac = atoi(optarg); break;

        case 'y': options.msm_type = atoi(optarg); break;
        case 'k': options.server_ip = strdup(optarg); break;
        case 'o': options.server_port = atoi(optarg); break;

        case 'x': options.file_output = strdup(optarg); break;
        case 'd': options.serial_port = strdup(optarg); break;
        case 'r': options.serial_port_baud_rate = atoi(optarg); break;
        case 'm': options.modem = strdup(optarg); break;
        case 'b': options.modem_baud_rate = atoi(optarg); break;
        default:
            abort ();
        }
    }

    return options;
}

int           connected = -1;
int           sockfd;
std::ofstream rtcm_file;
RTCMGenerator generator;
LPP_Client    client;
CellID        cell;
Modem_AT*     modem;
int           device;

bool provide_location_information_callback(LocationInformation* location, void* userdata);
bool provide_ecid_callback(ECIDInformation* ecid, void* userdata);
void assistance_data_callback(LPP_Client*, LPP_Transaction* transaction, LPP_Message* message,
                              void* userdata);
speed_t get_baud(long baud);

int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    cell         = CellID{
        .mcc  = options.mcc,
        .mnc  = options.mnc,
        .tac  = options.tac,
        .cell = options.cell_id,
    };

    printf("Location Server:    %s:%d %s\n", options.host, options.port, options.ssl ? "[ssl]" : "");
    printf("Cell:               MCC=%ld, MNC=%ld, TAC=%ld, Id=%ld\n", cell.mcc, cell.mnc, cell.tac,
           cell.cell);

    if (options.serial_port) {
        // Open serial port
        device = open(options.serial_port, O_RDWR);
        printf("OUTPUT Serial Port: %s\n", options.serial_port);
        if (device < 0) {
            printf("ERROR: Opening serial port failed. %s.\n", strerror(errno));
            return 1;
        }

        struct termios tios;
        tcgetattr(device, &tios);

        // Disable flow control, and ignore break and parity errors
        tios.c_iflag = IGNBRK | IGNPAR;
        tios.c_oflag = 0;
        tios.c_lflag = 0;

        // Determine validity of baud rate
        printf("OUTPUT Baud Rate:   %li\n", options.serial_port_baud_rate);

        // The get_baud function returns a baud rate of 0 for invalid baud rates
        if (get_baud(options.serial_port_baud_rate) == B0) {
            printf("ERROR: Invalid baud rate.\n");
            return 1;
        }

        // Set baud rate
        cfsetspeed(&tios, get_baud(options.serial_port_baud_rate));
        tcsetattr(device, TCSAFLUSH, &tios);

        // The serial port has a brief glitch once we turn it on which generates a start bit; sleep for 1ms to let it settle
        usleep(1000);
    }

    if (options.file_output) {
        // Create output file
        rtcm_file = std::ofstream{options.file_output};
        printf("OUTPUT File:        %s\n", options.file_output);
        if (!rtcm_file.is_open()) {
            printf("ERROR: Opening file output failed.\n");
            return 1;
        }
    }

    if (options.server_ip) {
        // Create output server
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("ERROR: Socket creation for output failed.\n");
            return 1;
        }

        struct sockaddr_in serveraddr;
        bzero(&serveraddr, sizeof(serveraddr));
        serveraddr.sin_family      = AF_INET;
        serveraddr.sin_addr.s_addr = inet_addr(options.server_ip);
        serveraddr.sin_port        = htons(options.server_port);

        printf("OUTPUT Server:      %s:%d \n", options.server_ip, options.server_port);
        connected = connect(sockfd, (sockaddr*)&serveraddr, sizeof(serveraddr));
        if (connected != 0) {
            printf("ERROR: Unable to connect to OUTPUT server.\n");
        } else {
            printf("Connect to OUTPUT server.\n");
        }
    }

    // Initialize OpenSSL
    network_initialize();

    // Register callback for when the location server request location
    // information from the device.
    client.provide_location_information_callback(NULL, provide_location_information_callback);

    // Register callback for when the location server request ECID and
    // measurements from the device.
    client.provide_ecid_callback(NULL, provide_ecid_callback);

    // Connect to location server
    if (!client.connect(options.host, options.port, options.ssl, cell)) {
        printf("ERROR: Connection failed. (%s:%i%s)\n", options.host, options.port,
               options.ssl ? " [ssl]" : "");
        return 0;
    }

    // Initialize Modem
    if (options.modem) {
        modem = new Modem_AT(options.modem, options.modem_baud_rate, cell);
        if (!modem->initialize()) {
            printf("ERROR: Modem connection failed. (device: %s, baud-rate: %u)\n", options.modem,
                   options.modem_baud_rate);
            return 0;
        }
    }

    // Enable generation of message for GPS, GLONASS, and Galileo.
    auto gnss = GNSSSystems{
        .gps     = true,
        .glonass = true,
        .galileo = true,
    };

    // Filter what messages you want generated.
    auto filter = MessageFilter{};
    if (options.msm_type == 4) {
        filter.msm.msm4 = true;
        filter.msm.msm5 = false;
        filter.msm.msm6 = false;
        filter.msm.msm7 = false;
    } else if (options.msm_type == 5) {
        filter.msm.msm4 = false;
        filter.msm.msm5 = true;
        filter.msm.msm6 = false;
        filter.msm.msm7 = false;
    } else if (options.msm_type == 6) {
        filter.msm.msm4 = false;
        filter.msm.msm5 = false;
        filter.msm.msm6 = true;
        filter.msm.msm7 = false;
    } else if (options.msm_type == 7) {
        filter.msm.msm4 = false;
        filter.msm.msm5 = false;
        filter.msm.msm6 = false;
        filter.msm.msm7 = true;
    }

    printf("MSM Messages:      ");
    if (filter.msm.msm4) printf(" MSM4");
    if (filter.msm.msm5) printf(" MSM5");
    if (filter.msm.msm6) printf(" MSM6");
    if (filter.msm.msm7) printf(" MSM7");
    printf("\n");

    // Create RTCM generator for converting LPP messages to RTCM messages.
    generator = RTCMGenerator{gnss, filter};

#if !SSR
    // Request assistance data (OSR) from server for the 'cell' and register a callback
    // when we receive assistance data.
    auto request = client.request_assistance_data(cell, NULL, assistance_data_callback);
#else
    // Request assistance data (SSR) from server for the 'cell' and register a callback
    // when we receive assistance data.
    auto request = client.request_assistance_data_ssr(cell, NULL, assistance_data_callback);
#endif
    if (request == AD_REQUEST_INVALID) {
        printf("ERROR: Requesting assistance data failed.\n");
        return 0;
    }

    // Run LPP client
    for (;;) {
        struct timespec timeout;
        timeout.tv_sec  = 0;
        timeout.tv_nsec = 1'000'000 * 100;  // 100 ms
        nanosleep(&timeout, NULL);

        // client.process() MUST be called at least once every second, otherwise
        // ProvideLocationInformation messages will send to the server.
        if (!client.process()) {
            printf("ERROR: Client has lost connection.\n");
            return 0;
        }
    }

    network_cleanup();
    return EXIT_SUCCESS;
}

bool provide_location_information_callback(LocationInformation* location, UNUSED void* userdata) {
    location->time = time(NULL);
    location->lat  = 20;
    location->lon  = 20;
    return true;
}

bool provide_ecid_callback(ECIDInformation* ecid, UNUSED void* userdata) {
    if (!modem) return false;

    auto neighbors = modem->neighbor_cells();
    auto cell      = modem->cell();
    if (!cell.has_value()) return false;

    ecid->cell           = cell.value();
    ecid->neighbor_count = 0;

    for (auto& neighbor_cell : neighbors) {
        if (ecid->neighbor_count < 16) {
            ecid->neighbors[ecid->neighbor_count++] = {
                .id     = neighbor_cell.id,
                .earfcn = neighbor_cell.EARFCN,
                .rsrp   = neighbor_cell.rsrp,
                .rsrq   = neighbor_cell.rsrq,
            };
        }
    }

    return true;
}

void assistance_data_callback(LPP_Client*, LPP_Transaction*, LPP_Message* message, void*) {
#if !SSR
    // Convert LPP message to buffer of RTCM coded messages.
    Generated     generated_messages{};
    unsigned char buffer[4 * 4096];
    auto          size   = sizeof(buffer);
    auto          length = generator.convert(buffer, &size, message, &generated_messages);

    printf("length: %4zu | msm%2i | ", length, generated_messages.msm);
    if (generated_messages.mt1074) printf("1074 ");
    if (generated_messages.mt1075) printf("1075 ");
    if (generated_messages.mt1076) printf("1076 ");
    if (generated_messages.mt1077) printf("1077 ");
    if (generated_messages.mt1084) printf("1084 ");
    if (generated_messages.mt1085) printf("1085 ");
    if (generated_messages.mt1086) printf("1086 ");
    if (generated_messages.mt1087) printf("1087 ");
    if (generated_messages.mt1094) printf("1094 ");
    if (generated_messages.mt1095) printf("1095 ");
    if (generated_messages.mt1096) printf("1096 ");
    if (generated_messages.mt1097) printf("1097 ");
    if (generated_messages.mt1030) printf("1030 ");
    if (generated_messages.mt1031) printf("1031 ");
    if (generated_messages.mt1230) printf("1230 ");
    if (generated_messages.mt1006) printf("1006 ");
    if (generated_messages.mt1032) printf("1032 ");
    printf("\n");
    if (length > 0) {
        // Write to file
        if (rtcm_file.is_open()) {
            rtcm_file.write((char*)buffer, length);
            rtcm_file.flush();
        }

        if (device > 0) {
        // Output to serial port
            write(device, (char*)buffer, length);
        }

        // Output to server
        if (connected == 0) {
            auto result = write(sockfd, buffer, length);
            if (result == -1) {
                connected = 0;
            }
        }
    }
#else
    // Extract SSR data
    printf("SSR LPP Message: %p\n", (void*)message);
#endif
}

speed_t get_baud(long baud) {
switch (baud) {
    case 50:
        return B50;
    case 75:
        return B75;
    case 110:
        return B110;
    case 134:
        return B134;
    case 150:
        return B150;
    case 200:
        return B200;
    case 300:
        return B300;
    case 600:
        return B600;
    case 1200:
        return B1200;
    case 1800:
        return B1800;
    case 2400:
        return B2400;
    case 4800:
        return B4800;
    case 9600:
        return B9600;
    case 19200:
        return B19200;
    case 38400:
        return B38400;
    case 57600:
        return B57600;
    case 115200:
        return B115200;
    case 230400:
        return B230400;
    default: 
        return B0;
    }
}
