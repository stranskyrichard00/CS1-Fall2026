#include "main.h"

using namespace std;

string findOrder(const string names[], int size) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < size; i++) {
        if (names[i] <= names[i - 1]) {
            increasing = false;
        }

        if (names[i] >= names[i - 1]) {
            decreasing = false;
        }
    }

    if (increasing) {
        return "INCREASING";
    }

    if (decreasing) {
        return "DECREASING";
    }

    return "NEITHER";
}