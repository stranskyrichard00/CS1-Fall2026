#include "grading.hpp"

using namespace std;

namespace grading {

char grade(const array<int, 5>& thresholds, int score) {
    constexpr char letters[] = {'A', 'B', 'C', 'D', 'E'};

    for (size_t i = 0; i < thresholds.size(); ++i) {
        if (score >= thresholds[i]) {
            return letters[i];
        }
    }

    return 'F';
}

}