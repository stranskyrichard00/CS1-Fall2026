#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/util.hpp"

using namespace std;

TEST_CASE("Official samples") {
    CHECK(firstOff({
        {400, 0}, {100, 1}, {300, 0}, {200, 1}
    }) == 300);

    CHECK(firstOff({
        {10, 1}, {2010, 1}, {150, 1}
    }) == -1);

    CHECK(firstOff({
        {250, 0}, {25, 1}, {100, 0},
        {50, 0}, {200, 1}, {150, 1}
    }) == 50);
}

TEST_CASE("One recording") {
    CHECK(firstOff({{100, 0}}) == 100);
    CHECK(firstOff({{100, 1}}) == -1);
}

TEST_CASE("Every recording is off") {
    CHECK(firstOff({{900, 0}, {100, 0}, {500, 0}}) == 100);
}

TEST_CASE("LED turns back on") {
    CHECK(firstOff({
        {30, 1}, {20, 0}, {10, 1}, {40, 0}
    }) == 20);
}

TEST_CASE("Earliest time appears last in input") {
    CHECK(firstOff({{300, 0}, {200, 0}, {100, 0}}) == 100);
}