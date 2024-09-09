# SOMEIP-Platform-Comparisons
Collection of SOME/IP projects across STM32, Raspberry Pi, and laptops. Illustrates code structure, library differences, and platform-specific considerations for automotive communication using SOME/IP. Aims to highlight implementation variations and provide comparative insights.

## Overview
This repo contains SOME/IP implementations on STM32, Raspberry Pi, and laptops to showcase code differences and platform-specific requirements.

## Platforms
- **STM32:** SOME/IP for STM32 microcontrollers.
- **Raspberry Pi:** SOME/IP on Raspberry Pi with a Linux environment.
- **Laptop:** SOME/IP on a Linux-based laptop.

## Getting Started

### repo structure
    SOMEIP-Platform-Comparisons/
    ├── stm32/
    │   ├── src/
    │   ├── include/
    │   ├── lib/
    │   ├── CMakeLists.txt
    │   └── README.md
    ├── raspberry-pi/
    │   ├── src/
    │   ├── include/
    │   ├── CMakeLists.txt
    │   ├── setup.sh
    │   └── README.md
    ├── laptop/
    │   ├── src/
    │   │   ├── hello_world_client_main.cpp
    │   │   ├── hello_world_service_main.cpp
    │   ├── include/
    │   │   ├── hello_world_client.hpp
    │   │   ├── hello_world_service.hpp
    │   ├── Makefile
    │   ├── install.sh
    │   └── README.md
    └── README.md

### Prerequisites
- Development tools for each platform.

### Installation
Navigate to the relevant directory and follow the specific instructions.

```bash
cd stm32
# Instructions for STM32

cd raspberry-pi
# Instructions for Raspberry Pi

cd laptop
# Instructions for Laptop

