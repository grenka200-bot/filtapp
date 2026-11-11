#include "spec_print.h"
#include <stdio.h>
#include <stddef.h>

int main (int argc, char *argv[]) {


    (void)printf("filtapp\n");

    for (size_t i = 1; i < argc; i++) {
        (void)printf("arcv[%lu] == %s\t", i, argv[i]);
    }
    (void)printf("\n");


    return 0;
}

