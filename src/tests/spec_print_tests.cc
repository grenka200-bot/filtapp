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

TEST(SpecRenderTest, RendersBarsWithBlock219) {
    double data[] = {0.25, 1.0, 0.5};
    char buf[256] = {0};
    int res = spec_render(data, 3, 4, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    EXPECT_STREQ(buf,
        "|   \xE2\x96\x88  \n"
        "|   \xE2\x96\x88  \n"
        "|   \xE2\x96\x88 \xE2\x96\x88\n"
        "| \xE2\x96\x88 \xE2\x96\x88 \xE2\x96\x88\n"
        "+------\n"
    );
}

TEST(SpecMathTest, DownsamplesSpectrumPreservingPeaks) {
    double src[] = {0.1, 0.9, 0.2, 0.4, 0.8, 0.3};
    double dst[3] = {0};
    size_t out_len = spec_downsample(src, 6, dst, 3);

    EXPECT_EQ(out_len, 3u);
    EXPECT_DOUBLE_EQ(dst[0], 0.9);
    EXPECT_DOUBLE_EQ(dst[1], 0.4);
    EXPECT_DOUBLE_EQ(dst[2], 0.8);
}

TEST(SpecRenderTest, LimitsOutputWidthForLargeArrays) {
    double data[100];
    for (int i = 0; i < 100; ++i) {
        data[i] = (i == 50) ? 1.0 : 0.0;
    }
    char buf[4096] = {0};
    int res = spec_render(data, 100, 2, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    const char* last_line = strchr(buf, '+');
    ASSERT_NE(last_line, nullptr);
    EXPECT_EQ(strlen(last_line), 1u + 32u * 2u + 1u); // '+' + 64 '-' + '\n'
}

TEST(SpecRenderTest, IncludesAxisLabels) {
    double data[] = {1.0};
    char buf[256] = {0};
    int res = spec_render_labeled(data, 1, 1, buf, sizeof(buf));

    EXPECT_EQ(res, 0);
    EXPECT_STREQ(buf,
        "A ^\n"
        "  | \xE2\x96\x88\n"
        "  +--> f\n"
    );
}

TEST(SpecPrintIntegrationTest, PrintsSpectrumToConsoleSuccessfully) {
    double data[] = {0.2, 0.5, 1.0, 0.7, 0.3, 0.1};
    EXPECT_EQ(spec_print(data, 6), 0);
    EXPECT_LT(spec_print(NULL, 6), 0);
    EXPECT_LT(spec_print(data, 0), 0);
}

