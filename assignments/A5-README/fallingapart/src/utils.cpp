#include "main.h"
#include <algorithm>
#include <functional>

using namespace std;


void sortPieces(int pieces[], int size) {
    sort(pieces, pieces + size, greater<int>());
}


int calculateScore(const int pieces[], int size, int player) {
    int total = 0;

    for (int i = player; i < size; i += 2) {
        total += pieces[i];
    }

    return total;
}