# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -fPIC -Iinclude -Wall -Wextra -I/home/mmeftah@actia.local/Downloads/capicxx-core-runtime/include $(shell pkg-config --cflags Qt5Widgets Qt5Gui Qt5Core)

# Libraries
LIBS = $(shell pkg-config --libs Qt5Widgets Qt5Gui Qt5Core) -lvsomeip3 -lCommonAPI-SomeIP

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
UI_DIR = ui

# Define sources and objects
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/dashboard.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
MOC_SRC = $(BUILD_DIR)/moc_dashboard.cpp
MOC_OBJ = $(BUILD_DIR)/moc_dashboard.o
UIC_HEADER = $(BUILD_DIR)/Dashboard.h

TARGET = $(BUILD_DIR)/dashboard

# Targets
all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(UIC_HEADER): $(UI_DIR)/Dashboard.ui
	@mkdir -p $(BUILD_DIR)
	uic $(UI_DIR)/Dashboard.ui -o $(UIC_HEADER)

$(MOC_SRC): $(UIC_HEADER)
	moc $(INCLUDE_DIR)/dashboard.hpp -o $(MOC_SRC)

$(MOC_OBJ): $(MOC_SRC)
	$(CXX) $(CXXFLAGS) -c $(MOC_SRC) -o $(MOC_OBJ)

$(TARGET): $(OBJ) $(MOC_OBJ)
	$(CXX) $(OBJ) $(MOC_OBJ) -o $(TARGET) $(LIBS)

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.cpp $(BUILD_DIR)/*.h $(TARGET)

.PHONY: all clean
