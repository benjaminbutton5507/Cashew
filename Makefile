

.PHONY: all

all: build/main.exe


build/main.exe: build/debug.o build/main.o
	g++ -std=c++23 -Wall -Werror build/debug.o build/main.o -o build/main.exe

build/debug.o: src/tools/debug/debug.cpp
	g++ -std=c++23 -Wall -Werror -c src/tools/debug/debug.cpp -o build/debug.o

build/main.o: src/main.cpp
	g++ -std=c++23 -Wall -Werror -c src/main.cpp -o build/main.o