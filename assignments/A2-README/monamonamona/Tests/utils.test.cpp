#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "header.hpp"

TEST_CASE("repeatWord repeats the first word three times") {
    CHECK(repeated::repeatWord("Mona", repeated::Count::Three)
          == "Mona Mona Mona");

    CHECK(repeated::repeatWord("Hanne", repeated::Count::Three)
          == "Hanne Hanne Hanne");

    CHECK(repeated::repeatWord("Helle", repeated::Count::Three)
          == "Helle Helle Helle");
}