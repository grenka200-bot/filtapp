FILTAPP = filtapp

CC = gcc
CPP = g++

CFLAGS = -Wall -fopenmp


.PHONY: all clean

all: filtapp tests

filtapp: src/main.c src/modules/dft_matr.c src/modules/dft_api.c src/modules/lowpass_filter.c src/modules/highpass_filter.c
	mkdir -p build
	$(CC) $(CFLAGS) src/main.c src/modules/dft_matr.c src/modules/dft_api.c src/modules/lowpass_filter.c src/modules/highpass_filter.c -o build/filtapp

tests:
	mkdir -p build
	$(CC) $(CFLAGS) -c src/modules/lowpass_filter.c -o build/lowpass_filter.o
	$(CPP) $(CFLAGS) src/tests/lowpass_filter_tests.cc build/lowpass_filter.o -o build/lowpass_filter_tests -lgtest -lgtest_main -pthread -lm
	rm -rf build/lowpass_filter.o

clean: 
	rm -rf build

