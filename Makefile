CC=g++
OUTPUT=matrices.bin
CFLAGS=-Wall -std=c++11 -o $(OUTPUT)

all: build run clean

build:
	$(CC) $(CFLAGS) matrix.cpp main.cpp

run: build
	./$(OUTPUT)

clean:
	rm *.bin
