#include "grading.hpp"

#include <iostream>

using namespace std;

int main() {
    array<int, 5> thresholds{};
    int score = 0;

    for (int& threshold : thresholds) {
        if (!(cin >> threshold)) {
            return 1;
        }
    }

    if (!(cin >> score)) {
        return 1;
    }

    cout << grading::grade(thresholds, score) << '\n';

    return 0;
}