#pragma once

#include <complex.h>
#include <stddef.h>

/**
 * @brief
 *  Функция пропускает нижние частоты сигнала 
 * @warning
 *  Изменению подвергается передаваемый объек, если что - пользуйтесь копией
 *  Функция работает с двусторонним спектром
 *  Коэффициент считается для одностороннего спектра
 *
 * @param spectrum
 *  Фильтруемый сигнал
 * @param spectrum_bins
 *  Число бинов в фильтруемом сигнале
 * @param cutoff_ratio
 *  Коэффициент среза
 *
 * @return
 *  0 - успех, 
 *  < 0 - неудача
 */
int lowpass_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio);

