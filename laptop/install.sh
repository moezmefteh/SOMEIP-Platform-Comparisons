#!/bin/bash

# Define directories
DOWNLOADS_DIR="$HOME/Downloads"

# Create necessary directories
mkdir -p ${DOWNLOADS_DIR}
mkdir -p ${LIB_DIR}
cd ${DOWNLOADS_DIR} || { echo "Failed to change directory to ${DOWNLOADS_DIR}"; exit 1; }

# Function to copy build artifacts to the library directory
copyToLib(){
    mkdir ../../../COMMONAPI 
    cp -d lib* ../../../COMMONAPI 
    cd ../../../
}

# Update package list
echo "Updating package list..."
sudo apt-get update

# Install necessary packages
echo "Installing build tools and libraries..."

# Remove any existing Boost installation
sudo apt-get --purge remove libboost-dev libboost-doc 2> /dev/null || true

# Install essential build tools and libraries
sudo apt-get install -y \
    build-essential \       # Includes g++, gcc, make, etc.
    cmake \                 # CMake for build system management
    net-tools \             # Network tools (e.g., ifconfig)
    wget \                  # To download files
    unzip \                 # To unzip downloaded files
    openjdk-11-jdk           # Updated Java version

# Download and install Boost from the official website
BOOST_VERSION=1_81_0
BOOST_TAR_FILE=boost_${BOOST_VERSION}.tar.gz
BOOST_URL=https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/${BOOST_TAR_FILE}

wget ${BOOST_URL} || { echo "Failed to download Boost"; exit 1; }
tar -xf ${BOOST_TAR_FILE} || { echo "Failed to extract Boost"; exit 1; }
cd boost_${BOOST_VERSION}/ || { echo "Failed to change directory to boost_${BOOST_VERSION}"; exit 1; }
./bootstrap.sh --prefix=/usr/
sudo ./b2
sudo ./b2 install
cd ${DOWNLOADS_DIR} || { echo "Failed to change directory to ${DOWNLOADS_DIR}"; exit 1; }

# Clone and build capicxx-core-runtime
git clone https://github.com/COVESA/capicxx-core-runtime.git || { echo "Failed to clone capicxx-core-runtime"; exit 1; }
cd capicxx-core-runtime || { echo "Failed to change directory to capicxx-core-runtime"; exit 1; }
git checkout tags/3.2.3
mkdir build
cd build || { echo "Failed to change directory to build"; exit 1; }
cmake ..
make -j
if [ $? -ne 0 ]; then
    echo "Error building capicxx-core-runtime"
    exit 1
fi
copyToLib
cd ${DOWNLOADS_DIR} || { echo "Failed to change directory to ${DOWNLOADS_DIR}"; exit 1; }

# Clone and build vSomeIP
git clone http://github.com/COVESA/vSomeIP.git || { echo "Failed to clone vSomeIP"; exit 1; }
cd vSomeIP || { echo "Failed to change directory to vSomeIP"; exit 1; }
git checkout tags/3.4.10
mkdir build
cd build || { echo "Failed to change directory to build"; exit 1; }
cmake ..
make -j
if [ $? -ne 0 ]; then
    echo "Error building vSomeIP"
    exit 1
fi
copyToLib
cd ${DOWNLOADS_DIR} || { echo "Failed to change directory to ${DOWNLOADS_DIR}"; exit 1; }

# Clone and build capicxx-someip-runtime
git clone https://github.com/COVESA/capicxx-someip-runtime.git || { echo "Failed to clone capicxx-someip-runtime"; exit 1; }
cd capicxx-someip-runtime || { echo "Failed to change directory to capicxx-someip-runtime"; exit 1; }
git checkout tags/3.2.3
mkdir build
cd build || { echo "Failed to change directory to build"; exit 1; }
cmake ..
make -j
sudo make install
if [ $? -ne 0 ]; then
    echo "Error building capicxx-someip-runtime"
    exit 1
fi
copyToLib
cd ${DOWNLOADS_DIR} || { echo "Failed to change directory to ${DOWNLOADS_DIR}"; exit 1; }

# Download and install generators
wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.1.12.4/commonapi-generator.zip || { echo "Failed to download commonapi-generator"; exit 1; }
wget https://github.com/COVESA/capicxx-someip-tools/releases/download/3.1.12/commonapi_someip_generator.zip || { echo "Failed to download commonapi_someip_generator"; exit 1; }
unzip commonapi-generator.zip -d commonapi-generator || { echo "Failed to unzip commonapi-generator"; exit 1; }
unzip commonapi_someip_generator.zip -d commonapi_someip_generator || { echo "Failed to unzip commonapi_someip_generator"; exit 1; }
chmod +x commonapi-generator/commonapi-generator-linux-x86_64
chmod +x commonapi_someip_generator/commonapi-someip-generator-linux-x86_64

# Set environment variables
echo "export LD_LIBRARY_PATH=${LIB_DIR}" >> ~/.bashrc

# Final instructions
echo "###############################################################"
echo "#                                                             #"
echo "#                 Usage of generators                          #"
echo "#                                                             #"
echo "# ${LIB_DIR}/commonapi-generator/commonapi-generator-linux-x86_64 -sk <fidl file>  #"
echo "# ${LIB_DIR}/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 -ll verbose <fdepl file>  #"
echo "#                                                             #"
echo "###############################################################"

echo "Installation complete. You can now build the project using CMake."

