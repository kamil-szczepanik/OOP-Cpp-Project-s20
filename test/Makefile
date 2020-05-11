CXX := g++
CXXFLAGS := -std=gnu++0x -g # -std=c++11 -std=gnu++0x
GTFLAGS := -lpthread

BUILD_DIR := build
OUTPUT_DIR := output
OBJ_DIR := obj
SOURCE_DIR := src
GTEST_DIR := ../lib/googletest
GTEST_MAIN := $(GTEST_DIR)/src/gtest_main.cc
LIBGTEST := $(BUILD_DIR)/libgtest.a

TARGET := proi-projekt-tests

TEST_SOURCES := $(wildcard $(SOURCE_DIR)/*.cpp)
TEST_O_FILES := $(patsubst %.cpp,%.o, $(subst $(SOURCE_DIR)/, $(BUILD_DIR)/$(OBJ_DIR)/, $(TEST_SOURCES)))
TEST_H_FILES := $(wildcard $(SOURCE_DIR)/*.h)

SOURCES := $(subst ../$(SOURCE_DIR)/main.cpp,, $(wildcard ../$(SOURCE_DIR)/*.cpp))
O_FILES := $(patsubst %.cpp,%.o, $(subst ../$(SOURCE_DIR)/, ../$(BUILD_DIR)/$(OBJ_DIR)/, $(SOURCES)))

$(TARGET): $(TEST_O_FILES) $(TEST_H_FILES) $(O_FILES) $(LIBGTEST)
	$(CXX) $(CXXFLAGS) $^ $(GTEST_MAIN) -isystem $(GTEST_DIR)/include -o $(BUILD_DIR)/$(OUTPUT_DIR)/$(TARGET) $(GTFLAGS)
	$(BUILD_DIR)/$(OUTPUT_DIR)/$(TARGET)

# kompilacja biblioteki gtest

$(LIBGTEST): | $(BUILD_DIR) $(BUILD_DIR)/$(OBJ_DIR) $(BUILD_DIR)/$(OUTPUT_DIR)
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -c ${GTEST_DIR}/src/gtest-all.cc -o build/libgtest.a

# generacja plików .o dla plików źródłowych testów

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/$(OBJ_DIR):
	cd build && mkdir $(OBJ_DIR)

$(BUILD_DIR)/$(OUTPUT_DIR):
	cd build && mkdir $(OUTPUT_DIR)

$(BUILD_DIR)/$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp | $(BUILD_DIR) $(BUILD_DIR)/$(OBJ_DIR) $(BUILD_DIR)/$(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(GTEST_DIR)/include -I../$(SOURCE_DIR)

# generacja plików .o dla plików źródłowych programu

../$(BUILD_DIR):
	cd .. && mkdir $(BUILD_DIR)

../$(BUILD_DIR)/$(OBJ_DIR):
	cd ../build && mkdir $(OBJ_DIR)

../$(BUILD_DIR)/$(OUTPUT_DIR):
	cd ../build && mkdir $(OUTPUT_DIR)

../$(BUILD_DIR)/$(OBJ_DIR)/%.o: ../$(SOURCE_DIR)/%.cpp | ../$(BUILD_DIR) ../$(BUILD_DIR)/$(OBJ_DIR) ../$(BUILD_DIR)/$(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@