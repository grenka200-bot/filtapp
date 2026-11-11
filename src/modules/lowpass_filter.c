#include "lowpass_filter.h"
#include "dft_matr.h"
#include <assert.h>


int lowpass_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio){
    
    assert(spectrum && spectrum_bins == TRANSFORM_ATTRIBUTE_N);
    assert(cutoff_ratio >= 0.0 && cutoff_ratio <= 1.0);


    // Считаем границу среза относительно одностороннего спектра (половины массива)
    size_t half_bins = spectrum_bins / 2;
    size_t cutoff_bin = (size_t)(half_bins * cutoff_ratio);

    #pragma omp parallel for
    for (size_t i = 0; i < spectrum_bins; i++) {
        // Вычисляем реальную частоту текущего бина с учетом симметрии спектра
        size_t freq = (i <= half_bins) ? i : (spectrum_bins - i);

        // Если частота выше границы среза — зануляем (вырезаем) бин
        if (freq > cutoff_bin) {
            spectrum[i] = 0.0 + 0.0 * I;
        }
    }

    return 0;
}

