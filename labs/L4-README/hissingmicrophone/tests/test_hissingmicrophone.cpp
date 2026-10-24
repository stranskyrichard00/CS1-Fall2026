#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <iostream>
#include "../src/utils.hpp"
using namespace std;

string checkHiss(const string& word);


TEST_CASE("Check for consecutive s characters") {
    CHECK(checkHiss("amiss") == "hiss");
    CHECK(checkHiss("octopuses") == "no hiss");
    CHECK(checkHiss("hiss") == "hiss");
}