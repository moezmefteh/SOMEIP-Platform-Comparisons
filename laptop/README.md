# SOME/IP Laptop

## Overview
This directory contains an example implementation of SOME/IP for a Linux-based laptop.

## Project Structure

The project is organized into the following directories:

- **`src/`**: Contains the source code for the project. This includes the main implementation files for the SOME/IP example.
- **`include/`**: Contains header files that define the interfaces and data structures used in the source code.
- **`build/`**: This directory is used for out-of-source builds and should be created during the build process.
- **`Makefile`**: The Makefile is used for building the project, managing dependencies, and specifying build rules.

## Getting Started

### Prerequisites

- **Boost**: Version 1.58 or later
- **CMake**: For build system management
- **CapICXX**: Core and SOME/IP runtime libraries
- **vSomeIP**: SOME/IP library
- **Java JDK**: Required for generators

### Installation

To set up the development environment on your laptop, execute the provided `install.sh` script:

    ./install.sh

##Building the Hello World Project

To build the project, navigate to the project directory and run:

    make all

This command will:

- Create the build/ directory if it doesn't exist.
- Compile the source code and place the resulting binaries in the build/ directory.

Running the Hello World Example

After building the project, you need to run the compiled binaries. First, start the service:

    VSOMEIP_CONFIGURATION=../config/helloworld-local.json VSOMEIP_APPLICATION_NAME=hello_world_service ./hello_world_service

In a separate terminal, run the client:

    VSOMEIP_CONFIGURATION=../config/helloworld-local.json VSOMEIP_APPLICATION_NAME=hello_world_client ./hello_world_client

Expected output service:

    2024-09-02 10:10:14.752623 [info] Using configuration file: "../config/helloworld-local.json".
    2024-09-02 10:10:14.753282 [info] Parsed vsomeip configuration in 0ms
    2024-09-02 10:10:14.753358 [info] Configuration module loaded.
    2024-09-02 10:10:14.753399 [info] Security disabled!
    2024-09-02 10:10:14.753431 [info] Initializing vsomeip (3.4.10) application "hello_world_service".
    2024-09-02 10:10:14.754047 [info] Instantiating routing manager [Host].
    2024-09-02 10:10:14.754778 [info] create_routing_root: Routing root @ /tmp/vsomeip-0
    2024-09-02 10:10:14.755311 [info] Application(hello_world_service, 4444) is initialized (11, 100).
    2024-09-02 10:10:14.755470 [info] Starting vsomeip application "hello_world_service" (4444) using 2 threads I/O nice 255
    2024-09-02 10:10:14.756208 [info] Client [4444] routes unicast:134.86.56.94, netmask:255.255.255.0
    2024-09-02 10:10:14.756375 [info] main dispatch thread id from application: 4444 (hello_world_service) is: 71b9cadfd640 TID: 16073
    2024-09-02 10:10:14.756632 [info] shutdown thread id from application: 4444 (hello_world_service) is: 71b9ca5fc640 TID: 16074
    2024-09-02 10:10:14.757235 [info] Watchdog is disabled!
    2024-09-02 10:10:14.757754 [info] io thread id from application: 4444 (hello_world_service) is: 71b9cc8feb80 TID: 16070
    2024-09-02 10:10:14.758031 [info] vSomeIP 3.4.10 | (default)
    2024-09-02 10:10:14.758292 [info] create_local_server: Listening @ /tmp/vsomeip-4444
    2024-09-02 10:10:14.758177 [info] io thread id from application: 4444 (hello_world_service) is: 71b9c95fa640 TID: 16076
    2024-09-02 10:10:14.758577 [info] OFFER(4444): [1111.2222:0.0] (true)
    2024-09-02 10:10:19.038588 [info] Application/Client 5555 is registering.
    2024-09-02 10:10:19.039509 [info] Client [4444] is connecting to [5555] at /tmp/vsomeip-5555
    2024-09-02 10:10:19.041422 [info] REGISTERED_ACK(5555)
    2024-09-02 10:10:19.143249 [info] REQUEST(5555): [1111.2222:255.4294967295]
    2024-09-02 10:10:19.147678 [info] RELEASE(5555): [1111.2222]
    2024-09-02 10:10:19.148227 [info] Application/Client 5555 is deregistering.
    2024-09-02 10:10:19.151448 [info] local_uds_client_endpoint_impl::receive_cbk Error: End of file
    2024-09-02 10:10:19.250286 [info] Client [4444] is closing connection to [5555]
    2024-09-02 10:10:24.148631 [info] STOP OFFER(4444): [1111.2222:0.0] (true)
    2024-09-02 10:10:24.150914 [info] Stopping vsomeip application "hello_world_service" (4444).

Expected output client

    2024-09-02 10:10:19.033342 [info] Using configuration file: "../config/helloworld-local.json".
    2024-09-02 10:10:19.033892 [info] Parsed vsomeip configuration in 0ms
    2024-09-02 10:10:19.033972 [info] Configuration module loaded.
    2024-09-02 10:10:19.034015 [info] Security disabled!
    2024-09-02 10:10:19.034050 [info] Initializing vsomeip (3.4.10) application "hello_world_client".
    2024-09-02 10:10:19.034093 [info] Instantiating routing manager [Proxy].
    2024-09-02 10:10:19.034424 [info] Client [5555] is connecting to [0] at /tmp/vsomeip-0
    2024-09-02 10:10:19.034492 [info] Application(hello_world_client, 5555) is initialized (11, 100).
    2024-09-02 10:10:19.034635 [info] Starting vsomeip application "hello_world_client" (5555) using 2 threads I/O nice 255
    2024-09-02 10:10:19.035588 [info] main dispatch thread id from application: 5555 (hello_world_client) is: 7347509ff640 TID: 16079
    2024-09-02 10:10:19.035830 [info] shutdown thread id from application: 5555 (hello_world_client) is: 7347501fe640 TID: 16080
    2024-09-02 10:10:19.036542 [info] io thread id from application: 5555 (hello_world_client) is: 734751544740 TID: 16078
    2024-09-02 10:10:19.036649 [info] io thread id from application: 5555 (hello_world_client) is: 73474f9fd640 TID: 16081
    2024-09-02 10:10:19.038040 [info] create_local_server: Listening @ /tmp/vsomeip-5555
    2024-09-02 10:10:19.038252 [info] Client 5555 (hello_world_client) successfully connected to routing  ~> registering..
    2024-09-02 10:10:19.038333 [info] Registering to routing manager @ vsomeip-0
    2024-09-02 10:10:19.040573 [info] Application/Client 5555 (hello_world_client) is registered.
    2024-09-02 10:10:19.143997 [info] ON_AVAILABLE(5555): [1111.2222:0.0]
    Sending: World
    2024-09-02 10:10:19.144786 [info] Client [5555] is connecting to [4444] at /tmp/vsomeip-4444
    Received: Hello World
    2024-09-02 10:10:19.147444 [info] Stopping vsomeip application "hello_world_client" (5555).
    2024-09-02 10:10:19.148985 [info] Application/Client 5555 (hello_world_client) is deregistered.
    2024-09-02 10:10:19.149638 [info] local_uds_client_endpoint_impl::receive_cbk Error: Operation canceled
    2024-09-02 10:10:19.149806 [info] Client [5555] is closing connection to [4444]
    2024-09-02 10:10:19.149864 [info] local_uds_client_endpoint_impl::receive_cbk Error: Operation canceled

Cleaning the Build

To clean up the build artifacts, use:

    make clean

This command will remove the compiled binaries and other generated files, allowing you to start a fresh build.
