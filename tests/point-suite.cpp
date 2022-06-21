#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, basic)
{
    point p{1,2};

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}

TEST(point_suite, move)
{
    point p{1,2};

    p.move(2, 3);

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);
}

TEST(point_suite, move_vector_addition)
{
    point p{1,2};
    point vec{2,3};

    p.move(vec);

    ASSERT_EQ(p.x(), 3);
    ASSERT_EQ(p.y(), 5);
}

TEST(point_suite, const_getters)
{
    const point p{1,2};

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}

static void do_something_with(const point* the_point)
{
//    the_point->move(1,1); // ERROR
}

TEST(point_suite, const_getters_function)
{
    point p{1,2};

    do_something_with(&p);

    p.move(1,2);   // point vec{1,2}; p += vec;  // moechte ich ...
}


TEST(point_suite, equality_inequality)
{
    point p1{1,2};
    point p2{3,4};

    // ASSERT_EQ(p1, p1);   // p1 == p1
    // ASSERT_NE(p1, p2);   // p1 != p2
}

TEST(point_suite, vector_addition)
{
    point p1{1,2};
    point p2{3,4};
    
    point p3 = p1 + p2;

    ASSERT_EQ(p3.x(), 4);
    ASSERT_EQ(p3.y(), 6);
}

TEST(point_suite, plus_equal)
{
    point p1{1,2};
    point vec{3,4};

    point p2 = p1 += vec;

    ASSERT_EQ(p1.x(), 4);
    ASSERT_EQ(p1.y(), 6);

    ASSERT_EQ(p2, p1);  // p2 == p1
}

TEST(point_suite, int_plus_equal)
{
    int i = 42;
    int j = i += 1;

    ASSERT_EQ(i, 43);
    ASSERT_EQ(j, i);
}
