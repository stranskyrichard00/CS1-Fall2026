#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/rectanglearea.hpp"

using namespace std;

TEST_CASE("Official samples") {
    CHECK(rectangleArea(0.0, 0.0, 3.0, 4.0)
          == doctest::Approx(12.0));

    CHECK(rectangleArea(5.2, -4.64, -3.47, 2.2)
          == doctest::Approx(59.3028));
}

TEST_CASE("Reversed corners") {
    CHECK(rectangleArea(3.0, 4.0, 0.0, 0.0)
          == doctest::Approx(12.0));
}

TEST_CASE("One coordinate increases while the other decreases") {
    CHECK(rectangleArea(0.0, 4.0, 3.0, 0.0)
          == doctest::Approx(12.0));
}

TEST_CASE("Negative coordinates") {
    CHECK(rectangleArea(-5.0, -6.0, -2.0, -2.0)
          == doctest::Approx(12.0));
}

TEST_CASE("Rectangle crosses both axes") {
    CHECK(rectangleArea(-2.0, -3.0, 2.0, 3.0)
          == doctest::Approx(24.0));
}

TEST_CASE("Fractional dimensions") {
    CHECK(rectangleArea(0.0, 0.0, 0.5, 0.25)
          == doctest::Approx(0.125));
}