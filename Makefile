FILTAPP = filtapp

CC = gcc
CFLAGS = -Wall -fopenmp


.PHONY: all clean

all: filtapp

filtapp: src/main.c src/modules/dft_matr.c src/modules/dft_api.c src/modules/lowpass_filter.c src/modules/highpass_filter.c
	mkdir -p build
	$(CC) $(CFLAGS) src/main.c src/modules/dft_matr.c src/modules/dft_api.c src/modules/lowpass_filter.c src/modules/highpass_filter.c -o build/filtapp

clean: 
	rm -rf build

