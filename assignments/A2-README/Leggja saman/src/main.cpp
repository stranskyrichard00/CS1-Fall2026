using namespace std;
#include <iostream>
#include <memory>
#include "headers.hpp"

using namespace std;

int main() {
    auto parkedCars = make_unique<long long[]>(2);

    cin >> parkedCars[static_cast<int>(parking::Driver::Arnar)]
        >> parkedCars[static_cast<int>(parking::Driver::Hannes)];

    cout << parking::totalCars(parkedCars.get()) << '\n';
    return 0;
}