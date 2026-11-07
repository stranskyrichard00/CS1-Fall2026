#include "pokerhand.hpp"

using namespace std;

int handStrength(const array<string, 5>& hand) {
    const string ranks = "A23456789TJQK";
    array<int, 13> counts{};
    int strength = 0;

    for (const string& card : hand) {
        size_t rank = ranks.find(card[0]);
        ++counts[rank];

        if (counts[rank] > strength) {
            strength = counts[rank];
        }
    }

    return strength;
}