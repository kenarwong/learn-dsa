CXX       := i686-linux-gnu-g++
CXX_FLAGS := -m32 -std=c++17 -ggdb -O2
#CXX       := g++
#CXX_FLAGS := -std=c++17 -ggdb

CLANG      	:= clang++
CLANG_FLAGS := -std=c++17 -Wall -Wextra -O2

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clang: $(BIN)/$(EXECUTABLE)_clang

$(BIN)/$(EXECUTABLE)_clang: $(SRC)/*.cpp
	$(CLANG) $(CLANG_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
