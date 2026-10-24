#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;

    string command;
    getline(cin, command);

    for (int i = 0; i < n; i++) {
        getline(cin, command);

        string instruction = followCommand(command);

        if (!instruction.empty()) {
            cout << instruction << '\n';
        }
    }

    return 0;
}