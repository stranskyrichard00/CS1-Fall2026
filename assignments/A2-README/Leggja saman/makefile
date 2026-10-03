CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++17
CPPFLAGS = -Isrc -Iexternal

PROGRAM = parking_total.exe
TEST = test_parking_total.exe

SRC = src/main.cpp src/utils.cpp
TEST_SRC = tests/utils.test.cpp

.PHONY: all build run unittest clean

all: build run unittest clean
 
build: $(PROGRAM)

$(PROGRAM): $(SRC) src/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC) -o $@

run: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(TEST_SRC) src/utils.cpp src/main.cpp tests/doctest.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_SRC) src/utils.cpp -o $@

unittest: $(TEST)
	./$(TEST)

clean:
	rm -f $(PROGRAM) $(TEST) *.o