#include <gtest/gtest.h>
#include <mystring.h>
#include <string.h>


TEST(my_string_suite, basic)
{
    MyString s("Hallo");
    ASSERT_EQ(s.size(), 5);
    ASSERT_EQ(strcmp(s.c_str(), "Hallo"), 0);
}

TEST(my_string_suite, copy_ctor)
{
    MyString original("Hallo");
    MyString copy{original};
}

TEST(my_string_suite, assignment_operator)
{
    MyString original("Hallo");
    MyString copy("Hello");
    copy = original;
}

TEST(my_string_suite, self_assignment)
{
    MyString original("Hallo");
    original = original;
}
