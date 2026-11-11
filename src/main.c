#include "dft_matr.h"
#include "spec_print.h"
#include "modules/lowpass_filter.h"
#include <stdio.h>
#include <stddef.h>

int main (int argc, char *argv[]) {

    // if --lowpass 1/4, то выключаем бины 4-15
    if (lowpass_filter(&signal) < 0) {
        (void)printf("error in lowpass_filter\n");
        return -1;
    }

    // if --hightpass 1/4, то выключаем бины 0-11

    (void)printf("filtapp\n");

    for (size_t i = 1; i < argc; i++) {
        (void)printf("arcv[%lu] == %s\t", i, argv[i]);
    }
    (void)printf("\n");


    return 0;
}

