#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/main.h"

using namespace std;

TEST_CASE("Sample 1: decreasing") {
    string names[] = {
        "JOE", "BOB", "ANDY", "AL", "ADAM"
    };

    CHECK(findOrder(names, 5) == "DECREASING");
}

TEST_CASE("Sample 2: neither") {
    string names[] = {
        "HOPE", "ALI", "BECKY", "JULIE", "MEGHAN",
        "LAUREN", "MORGAN", "CARLI", "MEGAN",
        "ALEX", "TOBIN"
    };

    CHECK(findOrder(names, 11) == "NEITHER");
}

TEST_CASE("Sample 3: increasing") {
    string names[] = {
        "GEORGE", "JOHN", "PAUL", "RINGO"
    };

    CHECK(findOrder(names, 4) == "INCREASING");
}

TEST_CASE("Two names in increasing order") {
    string names[] = {"AA", "ZZ"};

    CHECK(findOrder(names, 2) == "INCREASING");
}

TEST_CASE("Two names in decreasing order") {
    string names[] = {"ZZ", "AA"};

    CHECK(findOrder(names, 2) == "DECREASING");
}

TEST_CASE("Shared prefixes and a late change in direction") {
    string names[] = {"AL", "ALAN", "ALICE", "ALI"};

    CHECK(findOrder(names, 4) == "NEITHER");
}

TEST_CASE("Shorter prefixes come first") {
    string names[] = {"AL", "ALAN", "ALICE"};

    CHECK(findOrder(names, 3) == "INCREASING");
}

TEST_CASE("Function accepts a dynamic array") {
    string* names = new string[3];

    names[0] = "CAROL";
    names[1] = "BOB";
    names[2] = "AL";

    CHECK(findOrder(names, 3) == "DECREASING");

    delete[] names;
    names = nullptr;
}