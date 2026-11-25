#pragma once

#include <complex.h>
#include <stddef.h>

/**
 * @brief
 *  Функция приименяет ПФ для сигнала и сохраняет значение в буфер
 * @warning
 *  Функция принимает на вход сигнал в (N = 16) сэмплов
 *
 * @details
 *
 * @param signal
 *  Входной сигнал
 * @param signal_bins
 *  Размер сигнала (N = 16)
 * @param spectrum
 *  Буфер под спектр
 * @param spectrum_bins
 *  Размер буфера под спектр
 *
 * @return
 *  >= 0 - число бинов, занесенных в буфер, 
 *  < 0 - неудача
 */
int dft_apply(const complex double *signal, size_t signal_bins, complex double *spectrum, size_t spectrum_bins);

