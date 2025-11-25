CXX = g++
CFLAGS = -std=c++23 -Wall

debugging = src/debugging
foundation = src/foundations
math = $(foundation)/math

.PHONY: all

all: build/logger.o build/memory.o build/main.o
	$(CXX) $(CFLAGS) build/logger.o build/memory.o build/main.o -o build/main.exe

build/logger.o: $(debugging)/logger.cpp
	$(CXX) $(CFLAGS) -c $(debugging)/logger.cpp -o build/logger.o

build/memory.o: $(foundation)/memory.cpp
	$(CXX) $(CFLAGS) -c $(foundation)/memory.cpp -o build/memory.o

build/main.o: src/main.cpp
	$(CXX) $(CFLAGS) -c src/main.cpp -o build/main.o