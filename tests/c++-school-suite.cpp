#include <gtest/gtest.h>

#include <some-function.h>


TEST(cxx_school_suite, the_answer)
{
    int answer = the_answer();
    ASSERT_EQ(answer, 42);
}
