#include "spec_print.h"
#include "modules/lowpass_filter.h"
#include "modules/dft_api.h"
#include "modules/dft_matr.h"
#include <stdio.h>
#include <stddef.h>

int main (int argc, char *argv[]) {

    // испытуемый сигнал
    complex double signal[TRANSFORM_ATTRIBUTE_N] = {0};
    for (size_t i = 0; i < TRANSFORM_ATTRIBUTE_N; i++) {
        signal[i] = 1 + 0 * I;
    }
    (void)printf("signal done\n");
    
    complex double spec[TRANSFORM_ATTRIBUTE_N] = {0};

    if (dft_apply(signal, sizeof(signal) / sizeof(signal[0]), spec, sizeof(spec) / sizeof(spec[0])) < 0) {
        (void)printf("error in dft\n");
        return -1;
    }
    (void)printf("dft done\n");

    if (lowpass_filter(spec, sizeof(spec) / sizeof(spec[0]), 0.25) < 0) {
        (void)printf("error in lowpass_filter\n");
        return -1;
    }
    (void)printf("lowpass done\n");
    

    return 0;
}

