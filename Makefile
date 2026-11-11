FILTAPP = filtapp

CC = gcc
CFLAGS = -Wall


.PHONY: all clean

all: filtapp

filtapp: src/main.c src/dft_matr.c
	mkdir -p build
	$(CC) $(CFLAGS) src/main.c src/dft_matr.c -o build/filtapp

clean: 
	rm -rf build

