#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/doctest.h" // FIXME: adjust the path as needed
#include "../includes/utils.h"

TEST_CASE("Testing find_sum function")
{
    SUBCASE("Two positive numbers")
    {
        CHECK(my_space::find_sum(new big_int(10), new big_int(4)) == 14);
    }
    SUBCASE("One negative and one positive number")
    {
        big_int *pos = new big_int(4);
        big_int *neg = new big_int(-5);
        CHECK(my_space::find_sum(neg, pos) == -1);
        delete pos;
        delete neg;
    }
    // FIXME8: Add 2 more test cases to cover edge cases
    SUBCASE("One positive and 0")
    {
        big_int *pos = new big_int(4);
        big_int *neg = new big_int(0);
        CHECK(my_space::find_sum(neg, pos) == 4);
        delete pos;
        delete neg;
    }
      SUBCASE("One negative and one negative number")
    {
        big_int *pos = new big_int(-5);
        big_int *neg = new big_int(-7);
        CHECK(my_space::find_sum(neg, pos) == -12);
        delete pos;
        delete neg;
    }
    
}
TEST_CASE("Testing find_product function")
{
    SUBCASE("Two positive numbers")
    {
        large_int a = 6;
        large_int b = 7;
        CHECK(my_space::find_product(a, b) == 42);
    }
    SUBCASE("One negative and one positive number")
    {
        large_int *n1 = new large_int(10);
        large_int *n2 = new large_int(-5);
        CHECK(my_space::find_product(*n1, *n2) == -50);
        delete n1;
        delete n2;
    }
    // FIXME9: Add 2 more test cases to cover edge cases
    SUBCASE("Two negative numbers")
    {
        large_int *n1 = new large_int(-10);
        large_int *n2 = new large_int(-5);
        CHECK(my_space::find_product(*n1, *n2) == 50);
        delete n1;
        delete n2;
    }
     SUBCASE("A positive number and 0")
    {
        large_int *n1 = new large_int(10);
        large_int *n2 = new large_int(0);
        CHECK(my_space::find_product(*n1, *n2) == 0);
        delete n1;
        delete n2;
    }
}

// FIXME10: Write test cases (with at least 2 subcases) for find_difference function declared in utils.h
TEST_CASE("Testing find_difference function")
{
    SUBCASE("Two positive numbers")
    {
        large_int a = 6;
        large_int b = 7;
        CHECK(my_space::find_difference(a, b) == -1);
    }
    SUBCASE("One negative and one positive number")
    {
        large_int *n1 = new large_int(10);
        large_int *n2 = new large_int(5);
        CHECK(my_space::find_difference(*n1, *n2) == 5);
        delete n1;
        delete n2;
    }
}
// FIXME11: Write test cases (with at least 2 subcases) for find_larger function declared in utils.h
TEST_CASE("Testing find_larger function") {
    SUBCASE("Two positive numbers") {
        big_int n1(10);
        big_int n2(4);

        CHECK(my_space::find_larger(&n1, &n2) == 1);
    }


    SUBCASE("One negative and one positive number") {
        big_int n1(10);
        big_int n2(-6);
        CHECK(my_space::find_larger(&n1, &n2) == 1);
    }
}