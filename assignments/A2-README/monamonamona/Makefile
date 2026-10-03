CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++17
CPPFLAGS = -Isrc -Iexternal

PROGRAM = mona_mona_mona.exe
TEST = test_mona_mona_mona.exe

SRC = src/main.cpp src/utils.cpp
TEST_SRC = Tests/utils.test.cpp

.PHONY: all build run unittest clean

all: build unittest

build: $(PROGRAM)

$(PROGRAM): $(SRC) src/header.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC) -o $@

run: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(TEST_SRC) src/utils.cpp src/header.hpp Tests/doctest.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_SRC) src/utils.cpp -o $@

unittest: $(TEST)
	./$(TEST)

clean:
	rm -f $(PROGRAM) $(TEST) *.o