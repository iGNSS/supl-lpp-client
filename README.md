# SUPL LPP/RTCM Example Client

The SUPL LPP/RTCM client is provided as an example for connecting to Location Server using LPP (Location Positioning Protocol) via the Secure User-Plane Location (SUPL) 2.0 protocol and generating Radio Technical Commission for Maritime Services (RTCM) version 3 corrections for Real-time Kinematic (RTK) positioning.

To do this the code includes three libraries:

1. lpp: Handles LPP messages,
2. rtcm_generator: Generates RTCM from LPP messages,
3. modem: Gets cell information from a connected modem.

The client is given as an example on how these libraries are used by them self and together and is good base for developing a full feature client.

---

## Table of Contents

- [Getting Started](#getting-started)
- [Installing](#installing)
- [Usage](#usage)
- [License](#license)

---

## Installation

A step by step guide to installation of the client. The instructions below have been tested on Ubuntu 18.04, Ubuntu 20.04 and RaspberryPi OS (64 bit).

### Setup

Packages required can be install with the following command:

```console
sudo apt install make gcc cmake libssl-dev
```

### Build

First we create the `build` directory:

```console
mkdir build
cd build
```

The project build can be generated in Debug or Release mode. The commands below will generate the build as debug in the newly created directory `build/debug`. For release mode change `debug` to `release`.

```console
mkdir debug
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
```

Last step is to build the project. In `build/debug` or `build/release` run the following:

```console
make -j8
```

With a successful build, the example program executable (`supl-lpp-client`) should be available in the build directory.

---

## Usage

To use the client two mandatory options must be specified:

- `host` the location server hostname or IP address.
- `port` the locaiton server port number.

The RTCM used by the server is determined by the `mcc`, `mnc`, `tac`, `cellid` options. The servers are configured to serve RTCM streams for a specific location based on this information. Based on your location you'll need to start the client using different ID that will be provided from the server team.

The resulting RTCM messages can be output in a number of ways:

- To a server by providing a `server_ip` and `server_port`.
- To a file by providing a `file_output`.
- To a device by providing a `serial_port` and `serial_port_baud_rate`.

### Help prompt

```text
-h, --host                  mandatory hostname or IP address for the location server, string.
-p, --port                  mandatory port number for location server, integer.
-s, --ssl                   enable ssl, boolean, defaults to false
-c, --mcc                   2 or 3 digit mobile country code, integer.
-n, --mnc                   2 or 3 digit mobile network code, integer.
-i, --cellid                cell id, integer.
-t, --tac                   tracking area code, integer.
-y, --msm_type              msm type used for generation of RTCM messages, integer, default to -1 (best suitable)
-k, --server_ip             hostname or IP address for output server.
-o, --server_port           port number for output server, integer.
-x, --file_output           file path output, string.
-d, --serial_port           serial port path output, string.
-r, --serial_port_baud_rate serial port baud rate, integer.
-m, --modem_device          modem device path, string.
-b, --modem_baud_rate       modem device baud rate, integer.
```

### Examples

Streaming RTCM to device:

```console
./supl-lpp-client -h 123.456.78.910 -p 1234 -c 505 -n 2 -t 1 -i 5 -d /dev/ttyAMA0 -r 38400
```

Save RTCM to file:

```console
./supl-lpp-client -h 123.456.78.910 -p 1234 -c 505 -n 2 -t 1 -i 5 -x ~/output/supl-lpp.rtcm
```

---

## License

See LICENSE File.
