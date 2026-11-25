#include "spec_print.h"
#include <stddef.h>
#include <math.h>
#include <string.h>

#define BAR_BLOCK "\xE2\x96\x88"

static double spec_find_max(const double* data, size_t len) {
    if (!data || len == 0) {
        return 0.0;
    }
    double max_val = 0.0;
    for (size_t i = 0; i < len; ++i) {
        double v = fabs(data[i]);
        if (v > max_val) {
            max_val = v;
        }
    }

    return max_val;
}

int spec_render_grid(size_t width, size_t height, char* out_buf, size_t buf_size) {

    if (!out_buf || width == 0 || height == 0) {
        return -1;
    }
    size_t required = (width * 2 + 2) * (height + 1) + 1;
    if (buf_size < required) {
        return -2;
    }


    size_t pos = 0;

    for (size_t y = 0; y < height; ++y) {
        out_buf[pos++] = '|';
        for (size_t x = 0; x < width * 2; ++x) {
            out_buf[pos++] = ' ';
        }
        out_buf[pos++] = '\n';
    }

    out_buf[pos++] = '+';
    for (size_t x = 0; x < width * 2; ++x) {
        out_buf[pos++] = '-';
    }
    out_buf[pos++] = '\n';
    out_buf[pos] = '\0';

    return 0;
}

static size_t spec_calc_bar_height(double val, double max_val, size_t height) {
    if (max_val <= 0.0 || height == 0) {
        return 0;
    }
    double norm = fabs(val) / max_val;
    if (norm > 1.0) {
        norm = 1.0;
    }
    return (size_t)(norm * (double)height + 0.5);
}

#define BAR_BLOCK "\xE2\x96\x88"

int spec_render(const double* data, size_t len, size_t height, char* out_buf, size_t buf_size) {
    if (!data || !out_buf || len == 0 || height == 0) {
        return -1;
    }
    // Максимум 4 байта на отсчет (пробел + 3 байта UTF-8 '█')
    size_t required = (len * 4 + 2) * height + (len * 2 + 2) + 1;
    if (buf_size < required) {
        return -2;
    }

    double max_val = spec_find_max(data, len);
    size_t pos = 0;

    for (size_t row = 0; row < height; ++row) {
        size_t level = height - row;
        out_buf[pos++] = '|';
        for (size_t i = 0; i < len; ++i) {
            out_buf[pos++] = ' ';
            size_t bar_h = spec_calc_bar_height(data[i], max_val, height);
            if (bar_h >= level) {
                memcpy(out_buf + pos, BAR_BLOCK, 3);
                pos += 3;
            } else {
                out_buf[pos++] = ' ';
            }
        }
        out_buf[pos++] = '\n';
    }

    out_buf[pos++] = '+';
    for (size_t i = 0; i < len * 2; ++i) {
        out_buf[pos++] = '-';
    }
    out_buf[pos++] = '\n';
    out_buf[pos] = '\0';

    return 0;
}





