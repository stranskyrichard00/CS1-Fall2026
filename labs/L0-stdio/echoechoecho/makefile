.PHONY: all build run clean

all: build run clean

build:
	@g++ -c -Wall -std=c++17 src/echoechoecho.cpp
	@g++ -o echoechoecho.exe *.o

run:
	@./echoechoecho.exe

clean:
	@rm -f ./echoechoecho.exe *.o

# FIXME 7
# Write at least 3 more rules: all, run, and clean