#include "main.h"
#include <iostream>

using namespace std;
int main() {
    int size;

    if (!(cin >> size) || size <= 0) {
        return 1;
    }

    int* pieces = new int[size];

    for (int i = 0; i < size; i++) {
        if (!(cin >> pieces[i])) {
            delete[] pieces;
            return 1;
        }
    }

    sortPieces(pieces, size);

    int alice = calculateScore(pieces, size, 0);
    int bob = calculateScore(pieces, size, 1);

    cout << alice << " " << bob << '\n';

    delete[] pieces;
    pieces = nullptr;

    return 0;
}
