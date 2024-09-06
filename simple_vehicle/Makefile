# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude -Wall -Wextra -I/home/mmeftah@actia.local/COMMONAPI/include

# Libraries
LIBS = -L/home/mmeftah@actia.local/COMMONAPI -lvsomeip3

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
CLIENT_SRC = $(SRC_DIR)/client_main.cpp
SERVICE_SRC = $(SRC_DIR)/service_main.cpp

# Object files
CLIENT_OBJ = $(BUILD_DIR)/client_main.o
SERVICE_OBJ = $(BUILD_DIR)/service_main.o

# Executables
CLIENT_EXEC = $(BUILD_DIR)/client
SERVICE_EXEC = $(BUILD_DIR)/service

# Default target
all: $(BUILD_DIR) $(CLIENT_EXEC) $(SERVICE_EXEC)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Client executable
$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Service executable
$(SERVICE_EXEC): $(SERVICE_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compile client source file
$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile service source file
$(SERVICE_OBJ): $(SERVICE_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
