#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/utils.hpp"

TEST_CASE("Testing Avion") {
    string name1 = "N-FBI1";
    string name2 = "N321-CIA";
    string name3 = "FBI";

    CHECK(containsFBI(&name1) == true);
    CHECK(containsFBI(&name2) == false);
    CHECK(containsFBI(&name3) == true);
}