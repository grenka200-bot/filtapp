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

TEST(SpecMathTest, CalculatesDiscreteBarHeight) {
    EXPECT_EQ(spec_calc_bar_height(1.0, 1.0, 4), 4u);
    EXPECT_EQ(spec_calc_bar_height(0.5, 1.0, 4), 2u);
    EXPECT_EQ(spec_calc_bar_height(0.0, 1.0, 4), 0u);
    EXPECT_EQ(spec_calc_bar_height(50.0, 100.0, 4), 2u);
}

TEST(SpecMathTest, HandlesEdgeCasesInBarHeight) {
    EXPECT_EQ(spec_calc_bar_height(0.0, 0.0, 4), 0u);
    EXPECT_EQ(spec_calc_bar_height(0.01, 1.0, 4), 0u);
    EXPECT_EQ(spec_calc_bar_height(-1.0, 1.0, 4), 4u);
    EXPECT_EQ(spec_calc_bar_height(2.0, 1.0, 4), 4u);
}

TEST(SpecRenderTest, RendersZeroSpectrumAsEmptyGrid) {
    double data[] = {0.0, 0.0, 0.0};
    char buf[256] = {0};
    int res = spec_render(data, 3, 2, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    EXPECT_STREQ(buf,
        "|      \n"
        "|      \n"
        "+------\n"
    );
}


