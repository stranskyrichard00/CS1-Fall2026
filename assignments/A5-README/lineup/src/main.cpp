#include "main.h"
#include <iostream>

using namespace std;

int main() {
    int size;

    if (!(cin >> size) || size <= 0) {
        return 1;
    }

    string* names = new string[size];

    for (int i = 0; i < size; i++) {
        if (!(cin >> names[i])) {
            delete[] names;
            return 1;
        }
    }

    cout << findOrder(names, size) << '\n';

    delete[] names;
    names = nullptr;

    return 0;
}