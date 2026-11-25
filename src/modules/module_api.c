#include "module_api.h"
#include <assert.h>
#include <stdbool.h>

int apply_frequency_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio, filter_mode_t mode) {
    assert(spectrum && spectrum_bins > 0);
    assert(cutoff_ratio >= 0.0 && cutoff_ratio <= 1.0);

    size_t half_bins = spectrum_bins / 2;
    size_t cutoff_bin = (size_t)(half_bins * cutoff_ratio);

    #pragma omp parallel for
    for (size_t i = 0; i < spectrum_bins; i++) {
        size_t bin_distance = (i <= half_bins) ? i : (spectrum_bins - i);

        bool should_zero = (mode == FILTER_LOWPASS)
            ? (bin_distance > cutoff_bin)
            : (bin_distance < cutoff_bin);

        if (should_zero) {
            spectrum[i] = 0.0 + 0.0 * I;
        }
    }

    return 0;
}

