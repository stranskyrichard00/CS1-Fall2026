#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../src/header.hpp"
#include <utility>
using namespace std;


TEST_CASE("Testing greater function") {
    CHECK(greater_function(4, 5) == 5);
    CHECK(greater_function(7, 5) == 7);
    CHECK(greater_function(3, 3) == 3);
    CHECK(greater_function(-4, -5) == -4);   
}

