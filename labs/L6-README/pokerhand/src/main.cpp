#include "pokerhand.hpp"

#include <iostream>

using namespace std;

int main() {
    array<string, 5> hand{};

    for (string& card : hand) {
        if (!(cin >> card)) {
            return 1;
        }
    }

    cout << handStrength(hand) << '\n';

    return 0;
}