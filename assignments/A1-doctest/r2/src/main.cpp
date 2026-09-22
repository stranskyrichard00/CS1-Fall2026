#include <iostream>

#include "r2.hpp"


using namespace std;

//user input to plug into the function
int main() {

    int first, mean;

    cin >> first >> mean;

    cout << r2(first, mean) << endl;

    return 0;
}