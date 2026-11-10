#include "rectanglearea.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double x1, y1, x2, y2;

    if (!(cin >> x1 >> y1 >> x2 >> y2)) {
        return 1;
    }

    cout << fixed << setprecision(3)
         << rectangleArea(x1, y1, x2, y2) << '\n';

    return 0;
}