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
	$(CC) $(CFLAGS) -c src/spec_print.c -o build/spec_print.o
	$(CPP) $(CFLAGS) src/tests/spec_print_tests.cc build/spec_print.o -o build/spec_print_tests -lgtest_main -lgtest -pthread -lm -L/usr/local/lib
	rm -rf build/spec_print.o


clean: 
	rm -rf build

