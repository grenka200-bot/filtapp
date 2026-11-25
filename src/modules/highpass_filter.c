#include "highpass_filter.h"
#include "module_api.h"

int highpass_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio) {
    return apply_frequency_filter(spectrum, spectrum_bins, cutoff_ratio, FILTER_HIGHPASS);
}

