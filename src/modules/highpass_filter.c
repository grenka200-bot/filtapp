#include "highpass_filter.h"
#include <assert.h>

int highpass_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio) {

    assert(spectrum && spectrum_bins);
    assert(cutoff_ratio >= 0.0 && cutoff_ratio <= 1.0);


    // Граница среза рассчитывается относительно одностороннего спектра
    size_t half_bins = spectrum_bins / 2;
    size_t cutoff_bin = (size_t)(half_bins * cutoff_ratio);

    for (size_t i = 0; i < spectrum_bins; i++) {
        // Определяем реальную частоту бина с учетом симметрии двустороннего спектра
        size_t freq = (i <= half_bins) ? i : (spectrum_bins - i);

        // ФВЧ: зануляем все частоты, которые ниже заданного порога среза
        if (freq < cutoff_bin) {
            spectrum[i] = 0.0 + 0.0 * I;
        }
    }

    return 0;
}

