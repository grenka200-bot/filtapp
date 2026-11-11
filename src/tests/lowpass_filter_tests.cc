#include <gtest/gtest.h>

extern "C" {
    #include "../modules/lowpass_filter.h"
}

// Тест 1: Проверяем, что передача NULL вызывает срабатывание assert (аварийное завершение)
TEST(LowpassFilterDeathTest, CrashesOnNullSpectrum) {
    // EXPECT_DEATH запускает вызов в отдельном процессе и ждет, что он упадет
    EXPECT_DEATH(lowpass_filter(NULL, 16, 0.25), ".*");
}

// Тест 2: Проверяем, что на валидном массиве функция отрабатывает штатно (возвращает 0)
TEST(LowpassFilterTest, SucceedsOnValidSpectrum) {
    complex double spectrum;
    for (int i = 0; i < 16; i++) {
        spectrum[i] = 1.0 + 0.0 * I;
    }

    EXPECT_EQ(lowpass_filter(spectrum, 16, 0.25), 0);
}

