CXX := g++
CXXFLAGS := -std=c++11

BUILD_DIR := build
OUTPUT_DIR := output
OBJ_DIR := obj
SOURCE_DIR := src
GTEST_DIR = ./lib/googletest

TARGET := proi-projekt

SOURCES := $(wildcard $(SOURCE_DIR)/*.cpp)
O_FILES := $(patsubst %.cpp,%.o, \
					 $(subst $(SOURCE_DIR)/, $(BUILD_DIR)/$(OBJ_DIR)/, $(SOURCES)))
H_FILES := $(wildcard $(SOURCE_DIR)/*.h)
NON_CPP_H_FILES := # pliki .h niepowiązane z plikiem cpp

build-and-run: $(TARGET)
	$(BUILD_DIR)/$(OUTPUT_DIR)/$(TARGET)

test:
	cd test && make

.PHONY: test

$(TARGET): $(O_FILES) $(H_FILES) $(NON_CPP_H_FILES)
	$(CXX) $(CXXFLAGS) -g -o $(BUILD_DIR)/$(OUTPUT_DIR)/$(TARGET) $^

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(OBJ_DIR):
	cd build && mkdir $(OBJ_DIR)

$(BUILD_DIR)/$(OUTPUT_DIR):
	cd build && mkdir $(OUTPUT_DIR)

$(BUILD_DIR)/$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $(BUILD_DIR) $(BUILD_DIR)/$(OBJ_DIR) $(BUILD_DIR)/$(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -g -c $< -o $@