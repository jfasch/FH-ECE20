#include <gtest/gtest.h>
#include <copy-good.h>

TEST(copy_suite, copy_ctor_generated_empty)
{
    const HasTonsOfCrap original;

    ASSERT_EQ(original.str(), "");
    ASSERT_EQ(original.ints().size(), 0);

    HasTonsOfCrap copy{original};
    
    ASSERT_EQ(copy.str(), "");
    ASSERT_EQ(copy.ints().size(), 0);
}

TEST(copy_suite, copy_ctor_generated_full)
{
    HasTonsOfCrap original;

    original.add_one_more_piece_of_crap(42);
    original.add_one_more_piece_of_crap(43);
    original.add_one_more_piece_of_crap(44);
    original.add_one_more_piece_of_crap(45);
    original.add_one_more_piece_of_crap(100);

    original.add_something_to_str("Hallo");
    original.add_something_to_str(" ");
    original.add_something_to_str("Suesser");

    ASSERT_EQ(original.ints().size(), 5);
    ASSERT_EQ(original.ints()[0], 42);
    ASSERT_EQ(original.ints()[1], 43);
    ASSERT_EQ(original.ints()[2], 44);
    ASSERT_EQ(original.ints()[3], 45);
    ASSERT_EQ(original.ints()[4], 100);
    ASSERT_EQ(original.str(), "Hallo Suesser");

    HasTonsOfCrap copy{original};
    
    ASSERT_EQ(copy.ints().size(), 5);
    ASSERT_EQ(copy.ints()[0], 42);
    ASSERT_EQ(copy.ints()[1], 43);
    ASSERT_EQ(copy.ints()[2], 44);
    ASSERT_EQ(copy.ints()[3], 45);
    ASSERT_EQ(copy.ints()[4], 100);
    ASSERT_EQ(copy.str(), "Hallo Suesser");
}

TEST(copy_suite, assignment_operator)
{
    HasTonsOfCrap original;

    original.add_one_more_piece_of_crap(42);
    original.add_something_to_str("Hallo");

    HasTonsOfCrap copy;
    copy = original;

    ASSERT_EQ(copy.ints().size(), 1);
    ASSERT_EQ(copy.str(), "Hallo");
}

TEST(copy_suite, overloaded_copy_ctor)
{
    HasOverloadedCopy original("Das ist das Original");
    HasOverloadedCopy copy{original};

    ASSERT_EQ(copy.str(), "Das ist das Original (Kopie vom Constructor gemacht)");
}

TEST(copy_suite, overloaded_assignment_operator)
{
    HasOverloadedCopy original("Das ist das Original");
    HasOverloadedCopy copy;
    copy = original;

    ASSERT_EQ(copy.str(), "Das ist das Original (Kopie vom Assignment Operator gemacht)");

    HasOverloadedCopy copy1, copy2;

    copy1 = copy2 = original;
    //copy1 = copy2.operator=(original);
}
