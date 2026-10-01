#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h" // FIXME: adjust the path as needed
#include "../includes/utils.h"

TEST_CASE("Testing find_larger function")
{
    SUBCASE("First number is larger")
    {
        CHECK(my_functions::find_larger(10, 5) == 10);
    }
    SUBCASE("Second number is larger")
    {
        CHECK(my_functions::find_larger(3, 7) == 7);
    }
    // FIXME6: Add 2 more test cases to cover edge cases
    SUBCASE("Numbers are equal")
    {
        CHECK(my_functions::find_larger(5, 5) == 5);
    }
        SUBCASE("Both numbers are negative")
    {
        CHECK(my_functions::find_larger(-3, -7) == -3);
    }
}

TEST_CASE("Testing find_sum function")
{
    SUBCASE("First number larger than second")
    {
        CHECK(my_functions::find_sum(10, 4) == 14);
    }
    SUBCASE("Negative and positive numbers")
    {
        CHECK(my_functions::find_sum(-5, 4) == -1);
    }
    // FIXME7: Add 2 more test cases to cover edge cases
    SUBCASE("Both numbers are zero")
    {
        CHECK(my_functions::find_sum(0, 0) == 0);
    }
    SUBCASE("Both numbers are negative")
    {
    CHECK(my_functions::find_sum(-5, -4) == -9);
    }
}

TEST_CASE("Testing find_area_of_circle function")
{
    SUBCASE("Radius is positive")
    {
        CHECK(my_functions::find_area_of_circle(3.0) == doctest::Approx(28.274333882308138).epsilon(my_functions::EPSILON));
    }
    SUBCASE("Radius is zero")
    {
        CHECK(my_functions::find_area_of_circle(0.0) == doctest::Approx(0.0));
    }
    // FIXME8: Add 2 more test cases to cover edge cases
    SUBCASE("Radius is a fraction")
    {
    CHECK(my_functions::find_area_of_circle(0.5) ==
          doctest::Approx(0.7853981633974483).epsilon(my_functions::EPSILON));
    }
    SUBCASE("Radius is negative")
    {
    CHECK(my_functions::find_area_of_circle(-3.0) ==
          doctest::Approx(28.274333882308138).epsilon(my_functions::EPSILON));
    }
}
// FIXME9: Write test cases (with at least 2 subcases) for find_product function declared in utils.h
TEST_CASE("Testing find_product function")
{
    SUBCASE("Positive numbers")
    {
        CHECK(my_functions::find_product(3, 4) == 12);
    }
    SUBCASE("Negative and positive numbers")
    {
        CHECK(my_functions::find_product(-3, 4) == -12);
    }
}
// FIXME10: Write test cases for find_difference function (
TEST_CASE("Testing find_difference function")
{
    SUBCASE("First number is larger")
    {
        CHECK(my_functions::find_difference(10, 4) == 6);
    }
    SUBCASE("Second number is larger")
    {
        CHECK(my_functions::find_difference(3, 7) == -4);
    }
}
