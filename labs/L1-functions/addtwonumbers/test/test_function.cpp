#include "../headers/header.hpp"
#include <iostream>
#include <cassert>
using namespace std;

void test_add_two() {

    unsigned long a = add_two(9, 10);
    unsigned long expected = 19;
    assert(a == expected);

}

int main()
{

    test_add_two();
    cout << "All test cases are passed" << endl;
    return 0;

}