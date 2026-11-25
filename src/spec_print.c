#include "spec_print.h"
#include <stddef.h>
#include <math.h>


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






