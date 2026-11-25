#include <gtest/gtest.h>
#include "./../spec_print.c"

TEST(SpecGridTest, ScalesGridWidth) {
    char buf[256] = {0};
    int res = spec_render_grid(3, 1, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    EXPECT_STREQ(buf, "|      \n+------\n");
}

TEST(SpecGridTest, ScalesGridHeight) {
    char buf[256] = {0};
    int res = spec_render_grid(3, 3, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    EXPECT_STREQ(buf,
        "|      \n"
        "|      \n"
        "|      \n"
        "+------\n"
    );
}

TEST(SpecGridTest, RejectsZeroDimensions) {
    char buf[256] = {0};
    EXPECT_LT(spec_render_grid(0, 3, buf, sizeof(buf)), 0);
    EXPECT_LT(spec_render_grid(3, 0, buf, sizeof(buf)), 0);
}


TEST(SpecGridTest, ProtectsAgainstNullAndSmallBuffer) {
    char small_buf[4] = {0};
    EXPECT_LT(spec_render_grid(3, 3, NULL, 100), 0);
    EXPECT_LT(spec_render_grid(3, 3, small_buf, sizeof(small_buf)), 0);
}

TEST(SpecMathTest, FindsMaxAmplitude) {
    double data[] = {0.2, 1.5, 0.8, 1.5};
    EXPECT_DOUBLE_EQ(spec_find_max(data, 4), 1.5);
    EXPECT_DOUBLE_EQ(spec_find_max(NULL, 4), 0.0);
    EXPECT_DOUBLE_EQ(spec_find_max(data, 0), 0.0);
}




