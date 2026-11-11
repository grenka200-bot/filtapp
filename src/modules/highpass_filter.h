#pragma once

#include <complex.h>
#include <stddef.h>

/**
 * @brief
 *  Функция пропускает высокие частоты сигнала (подавляет низкие)
 * @warning
 *  Изменению подвергается передаваемый объект, если что - пользуйтесь копией.
 *  Функция работает с двусторонним спектром.
 *  Коэффициент считается для одностороннего спектра.
 *                                                                                   
 * @param spectrum     
 *  Фильтруемый спектр (двусторонний)
 * @param spectrum_bins
 *  Число бинов в фильтруемом спектре
 * @param cutoff_ratio
 *  Коэффициент частоты среза (от 0.0 до 1.0 для одностороннего спектра)
 *                                                      
 * @return       
 *  0 - успех,   
 *  < 0 - неудача
 */
int highpass_filter(complex double *spectrum, size_t spectrum_bins, double cutoff_ratio);

