cmake_minimum_required(VERSION 3.13)

project(BasicTest)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the CommonAPI install location
set(VSOMEIP_DIR "/home/mmeftah@actia.local/COMMONAPI")

# Find CommonAPI vsomeip3 package
find_package(vsomeip3 REQUIRED PATHS ${VSOMEIP_DIR} NO_DEFAULT_PATH)
# Find Boost package
find_package(Boost 1.55 REQUIRED COMPONENTS system thread log)

# Include directories
include_directories(
    ${COMMONAPI_DIR}/include
    ${Boost_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS}
)

# Define the executable
add_executable(service src/service.cpp)
add_executable(client src/client.cpp)
# Link the executable with the necessary libraries
target_link_libraries(service vsomeip3 ${Boost_LIBRARIES})
target_link_libraries(client vsomeip3 ${Boost_LIBRARIES})
