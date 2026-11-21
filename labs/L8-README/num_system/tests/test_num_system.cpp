#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/num_system.hpp"

#include <limits>
#include <stdexcept>

using namespace std;

TEST_CASE("Decimal to binary") {
    CHECK(fromDecimal(0, 2) == "0");
    CHECK(fromDecimal(1, 2) == "1");
    CHECK(fromDecimal(10, 2) == "1010");
    CHECK(fromDecimal(255, 2) == "11111111");
}

TEST_CASE("Decimal to octal") {
    CHECK(fromDecimal(0, 8) == "0");
    CHECK(fromDecimal(8, 8) == "10");
    CHECK(fromDecimal(64, 8) == "100");
    CHECK(fromDecimal(255, 8) == "377");
}

TEST_CASE("Decimal to hexadecimal") {
    CHECK(fromDecimal(0, 16) == "0");
    CHECK(fromDecimal(15, 16) == "F");
    CHECK(fromDecimal(16, 16) == "10");
    CHECK(fromDecimal(255, 16) == "FF");
}

TEST_CASE("Binary to decimal") {
    CHECK(toDecimal("0", 2) == 0);
    CHECK(toDecimal("1010", 2) == 10);
    CHECK(toDecimal("11111111", 2) == 255);
}

TEST_CASE("Octal to decimal") {
    CHECK(toDecimal("10", 8) == 8);
    CHECK(toDecimal("100", 8) == 64);
    CHECK(toDecimal("377", 8) == 255);
}

TEST_CASE("Hexadecimal to decimal") {
    CHECK(toDecimal("F", 16) == 15);
    CHECK(toDecimal("FF", 16) == 255);
    CHECK(toDecimal("ff", 16) == 255);
    CHECK(toDecimal("1a", 16) == 26);
}

TEST_CASE("Invalid inputs") {
    CHECK_THROWS_AS(toDecimal("102", 2), invalid_argument);
    CHECK_THROWS_AS(toDecimal("89", 8), invalid_argument);
    CHECK_THROWS_AS(toDecimal("G", 16), invalid_argument);
    CHECK_THROWS_AS(toDecimal("", 2), invalid_argument);
    CHECK_THROWS_AS(toDecimal("-1", 16), invalid_argument);
    CHECK_THROWS_AS(fromDecimal(10, 3), invalid_argument);
    CHECK_THROWS_AS(toDecimal("10", 3), invalid_argument);
}

TEST_CASE("Largest supported value converts back correctly") {
    auto maximum = numeric_limits<unsigned long long>::max();

    for (int base : {2, 8, 16}) {
        CHECK(toDecimal(fromDecimal(maximum, base), base) == maximum);
    }
}

TEST_CASE("Overflow is rejected") {
    string tooLarge =
        fromDecimal(numeric_limits<unsigned long long>::max(), 16) + "0";

    CHECK_THROWS_AS(toDecimal(tooLarge, 16), overflow_error);
}