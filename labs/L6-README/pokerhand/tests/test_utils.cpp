#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/pokerhand.hpp"

using namespace std;

TEST_CASE("Official samples") {
    CHECK(handStrength({"AC", "AD", "AH", "AS", "KD"}) == 4);
    CHECK(handStrength({"2C", "4D", "4H", "2D", "2H"}) == 3);
    CHECK(handStrength({"AH", "2H", "3H", "4H", "5H"}) == 1);
}

TEST_CASE("One pair") {
    CHECK(handStrength({"AC", "AD", "3H", "7S", "KD"}) == 2);
}

TEST_CASE("Two pairs") {
    CHECK(handStrength({"AC", "AD", "KH", "KS", "2D"}) == 2);
}

TEST_CASE("Three of a kind") {
    CHECK(handStrength({"QC", "QD", "QH", "2S", "3D"}) == 3);
}

TEST_CASE("Full house") {
    CHECK(handStrength({"JC", "JD", "JH", "KS", "KD"}) == 3);
}

TEST_CASE("Four of a kind") {
    CHECK(handStrength({"TC", "TD", "TH", "TS", "AD"}) == 4);
}

TEST_CASE("All ranks are different") {
    CHECK(handStrength({"AC", "2D", "5H", "9S", "KD"}) == 1);
}

TEST_CASE("Matching suits do not increase strength") {
    CHECK(handStrength({"2C", "4C", "6C", "8C", "TC"}) == 1);
}

TEST_CASE("Card order does not affect strength") {
    CHECK(handStrength({"KD", "AS", "AH", "AD", "AC"}) == 4);
}