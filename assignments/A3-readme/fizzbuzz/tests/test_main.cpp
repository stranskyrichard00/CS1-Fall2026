#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../src/header.hpp"
#include <utility>
using namespace std;


TEST_CASE("Testing Fizzbuzz function") {
    CHECK(fizzbuzz(6, 2, 3) == "FizzBuzz");
    CHECK(fizzbuzz(2, 2, 3) == "Fizz");
}

