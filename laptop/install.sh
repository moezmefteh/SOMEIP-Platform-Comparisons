#!/bin/bash

# Update package list
echo "Updating package list..."
sudo apt-get update

# Function to copy libraries to COMMONAPI directory
copyToLib() {
    mkdir -p ../../../COMMONAPI
    cp -d lib* ../../../COMMONAPI
    cd ../../
}

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
    openjdk-8-jdk           # Required for Java-based tools

# Download and install Boost from the official website https://www.boost.org/users/download/
BOOST_VERSION=1_86_0
BOOST_TAR_FILE=boost_${BOOST_VERSION}.tar.gz
BOOST_URL=https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/${BOOST_TAR_FILE}

wget ${BOOST_URL}
tar -xf ${BOOST_TAR_FILE}
cd boost_${BOOST_VERSION}/
./bootstrap.sh --prefix=/usr/
sudo ./b2
sudo ./b2 install
cd ..

# Clone and build capicxx-core-runtime
git clone https://github.com/COVESA/capicxx-core-runtime.git
cd capicxx-core-runtime
mkdir build
cd build
cmake ..
make -j
if [ $? -ne 0 ]; then
    echo "Error building capicxx-core-runtime"
    exit 1
fi
copyToLib
cd ../..

# Clone and build vSomeIP
git clone http://github.com/COVESA/vSomeIP.git
cd vSomeIP
mkdir build
cd build
cmake ..
make -j
if [ $? -ne 0 ]; then
    echo "Error building vSomeIP"
    exit 1
fi
copyToLib
cd ../..

# Clone and build capicxx-someip-runtime
git clone https://github.com/COVESA/capicxx-someip-runtime.git
cd capicxx-someip-runtime
mkdir build
cd build
cmake ..
make -j
sudo make install
if [ $? -ne 0 ]; then
    echo "Error building capicxx-someip-runtime"
    exit 1
fi
copyToLib
cd ../..

# Download and install generators
wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.1.12.4/commonapi-generator.zip
wget https://github.com/COVESA/capicxx-someip-tools/releases/download/3.1.12/commonapi_someip_generator.zip
unzip commonapi-generator.zip -d commonapi-generator
unzip commonapi_someip_generator.zip -d commonapi_someip_generator
chmod +x commonapi-generator/commonapi-generator-linux-x86_64
chmod +x commonapi_someip_generator/commonapi-someip-generator-linux-x86_64

# Set environment variables
echo "export LD_LIBRARY_PATH=${PWD}/COMMONAPI" >> ~/.bashrc

# Final instructions
echo "###############################################################"
echo "#                                                             #"
echo "#                 Usage of generators                          #"
echo "#                                                             #"
echo "# ~/commonapi-generator/commonapi-generator/commonapi-generator-linux-x86_64 -sk <fidl file>  #"
echo "# ~/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 -ll verbose <fdepl file>  #"
echo "#                                                             #"
echo "###############################################################"

echo "Installation complete. You can now build the project using CMake."

