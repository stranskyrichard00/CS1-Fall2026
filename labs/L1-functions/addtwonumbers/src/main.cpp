/*
Steps to Algorithm:
    1. need to develop an input command
    2. add the two commands then print them

    Defining functions should be done outside of int main()
*/
#include <iostream>
#include "../headers/header.hpp"
//can only include header files and never .cpp files

#include <string>
using namespace std;

//add a function signature/function Header
//unsigned long add_two(unsigned int a, unsigned int b); "Just for Demonstration"

int main()
{

    unsigned long a, b, sum; // declares varables will be integers

    cin >> a >> b; // takes input

    sum = add_two(a, b);

    cout << sum << endl;
    
    return 0;


}
