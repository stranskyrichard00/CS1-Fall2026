#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../external/doctest.h"
#include "../headers/header.hpp"


TEST_CASE("add_two function test") 
{
    unsigned int ans = add_two(2, 3);
    unsigned int expected = 5;
    CHECK(ans == expected);
    CHECK(add_two(2, 3) == 5);
    CHECK(add_two(0, 0) == 0);
    CHECK(add_two(100, 200) == 300);
}
