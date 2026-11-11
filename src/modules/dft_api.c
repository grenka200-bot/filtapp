#include "dft_api.h"
#include "dft_matr.h"
#include <assert.h>

int dft_apply(const complex double *signal, size_t signal_bins, complex double *spectrum, size_t spectrum_bins){

    assert(signal && spectrum);
    assert(signal_bins == TRANSFORM_ATTRIBUTE_N);
    assert(spectrum_bins >= TRANSFORM_ATTRIBUTE_N);


    for (size_t i = 0; i < TRANSFORM_ATTRIBUTE_N; i++) {
        
        complex double tmp = 0;

        for (size_t j = 0; j < TRANSFORM_ATTRIBUTE_N; j++) {
            tmp += signal[j] * dft_matr[i][j]; // сюда бы проверку на переполнение
        }
        spectrum[i] = tmp;
    }


    return TRANSFORM_ATTRIBUTE_N;
}

