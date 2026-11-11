#include <gtest/gtest.h>
#include <complex.h>

extern "C" {
    #define complex _Complex
    #include "../modules/lowpass_filter.h"
    #undef complex
}

// Тест 1: Проверяем, что передача NULL вызывает срабатывание assert (аварийное завершение)
TEST(LowpassFilterDeathTest, CrashesOnNullSpectrum) {
    // EXPECT_DEATH запускает вызов в отдельном процессе и ждет, что он упадет
    EXPECT_DEATH(lowpass_filter(NULL, 16, 0.25), ".*");
}

// Тест 2: Проверяем, что на валидном массиве функция отрабатывает штатно (возвращает 0)
TEST(LowpassFilterTest, SucceedsOnValidSpectrum) {
    double _Complex spectrum[16];
    for (int i = 0; i < 16; i++) {
        __real__ spectrum[i] = 1.0;
        __imag__ spectrum[i] = 0.0;
    }

    EXPECT_EQ(lowpass_filter(spectrum, 16, 0.25), 0);
}

