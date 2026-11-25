#pragma once

#include <complex.h>
#include <stddef.h>

typedef enum {
    FILTER_LOWPASS,
    FILTER_HIGHPASS
} filter_mode_t;

/**
 * @brief
 *  Общая функция частотной фильтрации двустороннего спектра
 *
 * @param spectrum
 *  Фильтруемый спектр
 * @param spectrum_bins
 *  Число бинов в спектре
 * @param cutoff_ratio
 *  Коэффициент среза (от 0.0 до 1.0)
 * @param mode
 *  Режим фильтрации (ФНЧ или ФВЧ)
 * @return
 *  0 - успех,
 *  < 0 при ошибке
 */
int apply_frequency_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio, filter_mode_t mode);

