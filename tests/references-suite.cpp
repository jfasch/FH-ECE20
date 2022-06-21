#include <gtest/gtest.h>


void pass_by_copy(int j)
{
    j = 666;
}

TEST(references_suite, copy)
{
    int i = 42;
    pass_by_copy(i);
    ASSERT_EQ(i, 42);
}



void pass_by_pointer(int* j)
{
    *j = 666;
}

TEST(references_suite, pointer)
{
    int i = 42;
    pass_by_pointer(&i);
    ASSERT_EQ(i, 666);
}




void pass_by_reference(int& j)
{
    j = 666;
}

TEST(references_suite, reference)
{
    int i = 42;
    pass_by_reference(i);
    ASSERT_EQ(i, 666);
}



struct person
{
    char firstname[128];
    char lastname[128];
};

void do_something_with(person p)
{
    p = {"Queen", "Elizabeth"};
}

TEST(references_suite, pass_by_copy_expensive)
{
    ASSERT_EQ(sizeof(person), 256);

    person p{"Joerg", "Faschingbauer"};
    do_something_with(p);
}

void do_something_with_const_reference(const person& p)
{
    // p = {"Queen", "Elizabeth"};   // ERROR!!
}

TEST(references_suite, pass_by_const_reference_inexpensive)
{
    ASSERT_EQ(sizeof(person), 256);

    person p{"Joerg", "Faschingbauer"};
    do_something_with_const_reference(p);
}
