#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/utils.hpp"

TEST_CASE("Testing compactName function") {
    CHECK(compactName("rooobert") == "robert");
    CHECK(compactName("aaabbbccc") == "abc");
    CHECK(compactName("robert") == "robert");
    CHECK(compactName("aaaaa") == "a");
    CHECK(compactName("a") == "a");
}