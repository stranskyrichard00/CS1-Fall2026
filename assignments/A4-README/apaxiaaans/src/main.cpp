#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;


int main() {
    string name;
    cin >> name;

    cout << compactName(name) << endl;

    return 0;
}