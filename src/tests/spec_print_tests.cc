#include <gtest/gtest.h>
#include "./../spec_print.c"

TEST(SpecGridTest, ScalesGridWidth) {
    char buf[256] = {0};
    int res = spec_render_grid(3, 1, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    EXPECT_STREQ(buf, "|      \n+------\n");
}




