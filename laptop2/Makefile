# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I$(INCLUDE_DIR) -Wall -Wextra -I/home/mmeftah@actia.local/Downloads/capicxx-core-runtime/include

# Libraries
LIBS = -lvsomeip3 -lCommonAPI-SomeIP

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Define sources and objects
SERVICE_SRC = $(SRC_DIR)/HelloWorldService.cpp
SERVICE_OBJ = $(BUILD_DIR)/HelloWorldService.o

CLIENT_SRC = $(SRC_DIR)/HelloWorldClient.cpp
CLIENT_OBJ = $(BUILD_DIR)/HelloWorldClient.o

# Executables
SERVICE_EXE = HelloWorldService
CLIENT_EXE = HelloWorldClient

# Targets
all: $(SERVICE_EXE) $(CLIENT_EXE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SERVICE_EXE): $(SERVICE_OBJ)
	$(CXX) $(SERVICE_OBJ) -o $@ $(LIBS)

$(CLIENT_EXE): $(CLIENT_OBJ)
	$(CXX) $(CLIENT_OBJ) -o $@ $(LIBS)

clean:
	rm -f $(BUILD_DIR)/*.o $(SERVICE_EXE) $(CLIENT_EXE)

.PHONY: all clean
