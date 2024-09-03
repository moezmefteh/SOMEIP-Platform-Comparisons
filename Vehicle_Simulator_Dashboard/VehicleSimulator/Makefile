# Compiler and flags
CXX = g++
QTCFLAG = $(shell pkg-config --cflags Qt5Widgets Qt5Gui Qt5Core)
CXXFLAGS = -std=c++11 -fPIC -Iinclude -Ibuild -Wall -Wextra -I/home/mmeftah@actia.local/Downloads/capicxx-core-runtime/include $(QTCFLAG)

# Libraries
QTLIB = $(shell pkg-config --libs Qt5Widgets Qt5Gui Qt5Core)
LIBS = $(QTLIB) -lvsomeip3 -lCommonAPI-SomeIP

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
UI_DIR = ui

# Define sources and objects
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/vehicle_simulator.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
UIC_HEADER = $(BUILD_DIR)/ui_vehicle_simulator.h
MOC_SRC = $(BUILD_DIR)/moc_vehicle_simulator.cpp
MOC_OBJ = $(BUILD_DIR)/moc_vehicle_simulator.o

TARGET = $(BUILD_DIR)/vehicle_simulator

# Targets
all: $(TARGET)

# Rule to generate the UI header file
$(UIC_HEADER): $(UI_DIR)/VehicleSimulator.ui
	uic $(UI_DIR)/VehicleSimulator.ui -o $(UIC_HEADER)

# Rule to generate the MOC source file
$(MOC_SRC): $(INCLUDE_DIR)/vehicle_simulator.hpp
	moc $(INCLUDE_DIR)/vehicle_simulator.hpp -o $(MOC_SRC)

# Rule to compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(UIC_HEADER) $(MOC_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile MOC file
$(MOC_OBJ): $(MOC_SRC)
	$(CXX) $(CXXFLAGS) -c $(MOC_SRC) -o $(MOC_OBJ)

# Rule to link the executable
$(TARGET): $(OBJ) $(MOC_OBJ)
	$(CXX) $(OBJ) $(MOC_OBJ) -o $(TARGET) $(LIBS)

# Clean up build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.cpp $(BUILD_DIR)/*.h $(TARGET)

.PHONY: all clean
