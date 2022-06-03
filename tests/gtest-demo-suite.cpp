#include <gtest/gtest.h>


TEST(gtest_demo_suite, passes)
{
    int a = 1;
    int b = 1;

    ASSERT_EQ(a, b);
}

// TEST(gtest_demo_suite, fails)
// {
//     int a = 1;
//     int b = 2;

//     ASSERT_EQ(a, b);
// }

TEST(gtest_demo_suite, passes_nocheinmal)
{
    int a = 1;
    int b = 2;

    ASSERT_NE(a, b);
}
