#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/titlecost.hpp"

using namespace std;

TEST_CASE("Official samples") {
    CHECK(transmissionCost("GoneWithTheWind", 13.341)
          == doctest::Approx(13.341).epsilon(1e-12));

    CHECK(transmissionCost("Gigi", 93.7) == 4.0);

    CHECK(transmissionCost("PieHard", 3.14159265358979323846)
          == doctest::Approx(3.14159265358979323846).epsilon(1e-12));
}

TEST_CASE("Cap below the title length") {
    CHECK(transmissionCost("Movie", 2.5)
          == doctest::Approx(2.5).epsilon(1e-12));
}

TEST_CASE("Cap equal to the title length") {
    CHECK(transmissionCost("Movie", 5.0) == 5.0);
}

TEST_CASE("Cap above the title length") {
    CHECK(transmissionCost("Movie", 100.0) == 5.0);
}

TEST_CASE("Single-character title") {
    CHECK(transmissionCost("A", 5.0) == 1.0);
    CHECK(transmissionCost("A", 0.5)
          == doctest::Approx(0.5).epsilon(1e-12));
}

TEST_CASE("Thirty-character title") {
    const string title(30, 'A');

    CHECK(transmissionCost(title, 40.0) == 30.0);
    CHECK(transmissionCost(title, 29.75)
          == doctest::Approx(29.75).epsilon(1e-12));
}

TEST_CASE("Mixed uppercase and lowercase letters") {
    CHECK(transmissionCost("aBcDeF", 10.0) == 6.0);
}

TEST_CASE("Cap just below the title length") {
    CHECK(transmissionCost("Movie", 4.99999999)
          == doctest::Approx(4.99999999).epsilon(1e-12));
}