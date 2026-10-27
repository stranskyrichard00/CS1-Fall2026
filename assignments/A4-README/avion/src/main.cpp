#include <iostream>
#include "utils.hpp"
using namespace std;

int main() {
    string name;
    bool found = false;

    for (int i = 1; i <= 5; i++) {
        cin >> name;

        if (containsFBI(&name)) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "HE GOT AWAY!";
    }

    cout << endl;
    return 0;
}