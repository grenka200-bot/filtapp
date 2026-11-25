#include "spec_print.h"
#include <stddef.h>

int spec_render_grid(size_t width, size_t height, char* out_buf, size_t buf_size) {
    (void)height;
    (void)buf_size;
    size_t pos = 0;

    out_buf[pos++] = '|';
    for (size_t x = 0; x < width * 2; ++x) {
        out_buf[pos++] = ' ';
    }
    out_buf[pos++] = '\n';

    out_buf[pos++] = '+';
    for (size_t x = 0; x < width * 2; ++x) {
        out_buf[pos++] = '-';
    }
    out_buf[pos++] = '\n';
    out_buf[pos] = '\0';

    return 0;
}





