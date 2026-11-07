#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/grading.hpp"

using namespace std;

TEST_CASE("Official samples") {
    CHECK(grading::grade({90, 89, 70, 60, 50}, 40) == 'F');
    CHECK(grading::grade({100, 99, 98, 97, 96}, 97) == 'D');
}

TEST_CASE("Exact thresholds earn the corresponding grade") {
    const array<int, 5> thresholds{90, 80, 70, 60, 50};

    CHECK(grading::grade(thresholds, 90) == 'A');
    CHECK(grading::grade(thresholds, 80) == 'B');
    CHECK(grading::grade(thresholds, 70) == 'C');
    CHECK(grading::grade(thresholds, 60) == 'D');
    CHECK(grading::grade(thresholds, 50) == 'E');
}

TEST_CASE("Scores just below each threshold") {
    const array<int, 5> thresholds{90, 80, 70, 60, 50};

    CHECK(grading::grade(thresholds, 89) == 'B');
    CHECK(grading::grade(thresholds, 79) == 'C');
    CHECK(grading::grade(thresholds, 69) == 'D');
    CHECK(grading::grade(thresholds, 59) == 'E');
    CHECK(grading::grade(thresholds, 49) == 'F');
}

TEST_CASE("Scores between thresholds") {
    const array<int, 5> thresholds{90, 80, 70, 60, 50};

    CHECK(grading::grade(thresholds, 95) == 'A');
    CHECK(grading::grade(thresholds, 85) == 'B');
    CHECK(grading::grade(thresholds, 75) == 'C');
    CHECK(grading::grade(thresholds, 65) == 'D');
    CHECK(grading::grade(thresholds, 55) == 'E');
    CHECK(grading::grade(thresholds, 45) == 'F');
}

TEST_CASE("Minimum and maximum scores") {
    const array<int, 5> thresholds{90, 80, 70, 60, 50};

    CHECK(grading::grade(thresholds, 0) == 'F');
    CHECK(grading::grade(thresholds, 100) == 'A');
}

TEST_CASE("Consecutive thresholds") {
    const array<int, 5> thresholds{100, 99, 98, 97, 96};

    CHECK(grading::grade(thresholds, 100) == 'A');
    CHECK(grading::grade(thresholds, 99) == 'B');
    CHECK(grading::grade(thresholds, 98) == 'C');
    CHECK(grading::grade(thresholds, 97) == 'D');
    CHECK(grading::grade(thresholds, 96) == 'E');
    CHECK(grading::grade(thresholds, 95) == 'F');
}