#ifndef GRADING_HPP
#define GRADING_HPP

#include <array>

using namespace std;

namespace grading {
    char grade(const array<int, 5>& thresholds, int score);
}

#endif