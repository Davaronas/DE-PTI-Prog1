CC = g++
INCLUDE_DIR = include
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
FLAGS = -c -Wall -O3 -std=c++11 -I $(INCLUDE_DIR)
EXECUTABLE = $(BIN_DIR)/binary_tree
MAIN= $(BUILD_DIR)/binary_tree.o
MAIN_SRC = $(SRC_DIR)/binary_tree.cpp
BT = $(BUILD_DIR)/BT.o
BT_SRC = $(SRC_DIR)/BT.cpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN) $(BT)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^

$(MAIN): $(MAIN_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $@ $<

$(BT): $(BT_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $@ $<

clean:
	rm -r $(BUILD_DIR)
	rm -r $(BIN_DIR)
