# SUPL LPP/RTCM Example Client

The SUPL LPP/RTCM client is provided as an example client for connecting to Location Server using LPP (Location Positioning Protocol) via the Secure User-Plane Location (SUPL) 2.0 protocol and generating Radio Technical Commission for Maritime Services (RTCM) version 3 corrections for Real-time Kinematic (RTK) positioning.

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

A step by step guide to installation of the client. The instructions below are tested on Ubuntu 18.04, Ubuntu 20.04 and RaspberryPi OS (64 bit).

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

With a successful build, the example program executable (`example`) should be available in the build directory.

---

## Usage

To use the example client a few arguments must be specified: `host` the location server address (`port` can be left as default most of the time). The RTCM used by the server is determined by the `mcc`, `mnc`, `tac`, `cellid`. The servers are configured to serve RTCM streams for a specific location based on this information. Based on your location you'll need to start the client using different ID that will be provided from the server team. Or use the modem to request a assistance data for a new cell.

The help prompt:

```console
./example

options:
Client takes the following options
-h, --host                  hostname or IP address for LS server, string, defaults to 129.192.82.208
-p, --port                  port number for LS server, integer, defaults to 5431
-s, --ssl                   enable ssl, boolean, defaults to false
-c, --mcc                   2 or 3 digit mobile country code, integer, defaults to 310
-n, --mnc                   2 or 3 digit mobile network code, integer, defaults to 260
-i, --cellid                cell id, integer, defaults to 3
-t, --tac                   tracking area code, integer, defaults to 1
-y, --msm_type              msm type used for generation of RTCM messages, integer, default to -1 (best suitable)
-k, --server_ip             hostname or IP address for output server, string, defaults to ""
-o, --server_port           port number for output server, integer, defaults to 3000
-x, --file_output           file path output, string, defaults to "" (no file output)
-d, --serial_port           serial port path output, string, defaults to "/dev/ttyAMA0"
-r, --serial_port_baud_rate serial port baud rate, integer, defaults to 38400
-m, --modem_device          modem device path, string, defaults to "" (no modem connected)
-b, --modem_baud_rate       modem device baud rate, integer, defaults to 9600
```

---

## License

See LICENSE File.
