

all: build run clean

build:
	g++ -o addtwo.exe src/main.cpp test/function.cpp

run:
	./addtwo.exe

clean:
	rm addtwo.exe

unit_test:
	g++ -o test_function.exe src/function.cpp test/test_function.cpp ./test_function.exe

doctest:
	g++ -o doctest.exe src/function.cpp test/test_doctest.cpp
	./doctest.exe