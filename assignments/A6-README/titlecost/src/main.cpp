#include "titlecost.hpp"

#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string title;
    double cap;

    if (!(cin >> title >> cap)) {
        return 1;
    }

    cout << setprecision(15)
         << transmissionCost(title, cap) << '\n';

    return 0;
}