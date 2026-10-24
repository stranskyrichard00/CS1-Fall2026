#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

std::string followCommand(const std::string& command);

TEST_CASE("Follow commands beginning with Simon says") {
    CHECK(followCommand("Simon says smile.") == " smile.");
    CHECK(followCommand("Simon says raise your right hand.")
          == " raise your right hand.");
}

TEST_CASE("Ignore other commands") {
    CHECK(followCommand("Lower your right hand.") == "");
    CHECK(followCommand("simon says smile.") == "");
    CHECK(followCommand("Simon Says smile.") == "");
    CHECK(followCommand("Simon saysomething.") == "");
}