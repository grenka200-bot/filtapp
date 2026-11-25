#pragma once
#include <stddef.h>

/**
 * @brief
 *  Функция "пишет" график в консоль
 *
 * @param data
 *  Массив вещественных чисел
 * @param len
 *  Число чисел
 *
 * @return
 *  0 - успех, 
 *  < 0 - неудача
 */
int spec_print(const double* data, size_t len);

