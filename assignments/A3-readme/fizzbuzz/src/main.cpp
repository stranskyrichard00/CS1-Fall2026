// Programmer name: Richard Stransky

#include <iostream>
#include "header.hpp"
using namespace std;

int main(){
    int * x = new int;
    int * y = new int;
    int n;
    cin >> *x >> *y >> n;
    // loop that goes up and see if it is divisible by provided integers
     for (int number = 1; number <= n; number++) {
        cout << fizzbuzz(number, *x, *y) << '\n';
     }
    delete x;
    delete y;

    return 0;



}