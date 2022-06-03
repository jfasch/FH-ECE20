#include <gtest/gtest.h>

#include <string.h> // C string
#include <string>


// DAS WOLLEN WIR NICHT! AUF GAR KEINEN FALL!!!
TEST(cxx_string_suite, c_string)
{
    char str[] = "hallo";
    char str_2[] = { 'h', 'a', 'l', 'l', 'o', '\0' };

    {
        ASSERT_EQ(strlen(str), 5);
        ASSERT_EQ(sizeof(str), 6);

        ASSERT_EQ(strlen(str_2), 5);
        ASSERT_EQ(sizeof(str_2), 6);
    }

    // strcat -> "hallo suesser"
    {
        char str_3[] = " suesser";
        char sum_str[5 /*"hallo"*/ + 8 /*" suesser"*/ + 1 /*terminating NULL byte!!!*/];
        sum_str[0] = '\0';

        strcat(sum_str, str);
        strcat(sum_str, str_3);

        int cmp = strcmp(sum_str, "hallo suesser");
        ASSERT_EQ(cmp, 0);
    }
}

TEST(cxx_string_suite, size)
{
    std::string s1 = "hallo";  // initialization (-> constructor)
    std::string s2{"hallo"};  // initialization (-> constructor)

    ASSERT_EQ(s1.size(), 5);  // method
    ASSERT_EQ(s2.size(), 5);  // method
};

TEST(cxx_string_suite, addition_equality)
{
    std::string s1 = "hallo";
    std::string s2 = " suesser";
    std::string sum_str = s1 + s2;  // addition operator

    ASSERT_TRUE(sum_str == "hallo suesser"); // equality operator
}

TEST(cxx_string_suite, comparison)
{
    std::string s1 = "faschingbauer";
    std::string s2 = "haubenhofer";

    ASSERT_TRUE(s1 < s2);
}
