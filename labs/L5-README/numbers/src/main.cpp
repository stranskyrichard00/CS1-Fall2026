#include <iostream>
#include <string>
#include "main.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        string numbers;
        cin >> numbers;

        cout << makeNice(numbers) << '\n';
    }

    return 0;
}