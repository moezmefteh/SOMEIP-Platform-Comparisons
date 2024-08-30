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

'./install.sh'

##Building the Project

To build the project, navigate to the project directory and run:

'make all'

This command will:

    Create the build/ directory if it doesn't exist.
    Compile the source code and place the resulting binaries in the build/ directory.

Running the Example

After building the project, you need to run the compiled binaries. First, start the service:

'./build/hello_world_service'

In a separate terminal, run the client:

'./build/hello_world_client'

Cleaning the Build

To clean up the build artifacts, use:

'make clean'

This command will remove the compiled binaries and other generated files, allowing you to start a fresh build.
