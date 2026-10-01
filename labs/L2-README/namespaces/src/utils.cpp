#include <iostream>
#include "../includes/utils.h"

using namespace std;

// Menu options
void show_menu(void)
{
    cout << "Enter one of the following menu options:\n";
    cout << "[1] Add two integers\n";
    cout << "[2] Multiply two integers\n";
    cout << "[3] Subtract one integer from another\n";
    cout << "[4] Find the larger of two integers\n";
    cout << "[5] Quit the program\n";
    cout << "[6] Find the area of a circle\n";
    cout << "Enter your choice [1-6]: ";
}

// function returns OPERATION type given character choice
OPERATION get_operation(char choice)
{
    OPERATION op;
    switch (choice)
    {
    case '1':
        op = ADD;
        break;
    case '2':
        op = MULTIPLY;
        break;
    // FIXME3 - add case for other operations in enum type
    case '3':
        op = LARGER;
        break;
    case '4':
        op = SUBTRACT;
        break;
    case '5':
        op = AREAOFCIRC;
    default:
        op = QUIT;
    }
    return op;
}

double my_functions::find_area_of_circle(const double radius)
{
    return my_functions::PI * radius * radius;
}

// must use my_functions namespace to resolve findSum function
big_int my_functions::find_sum(const big_int n1, const big_int n2)
{
    // dereference pointers n1 and n2 before adding their values
    return n1 + n2;
}

// define find_larger function declared inside my_functions namespace
// function returns the larger of the two given numbers
big_int my_functions::find_larger(const big_int n1, const big_int n2)
{
    // FIXME4: implement the function to return the larger of two numbers
    return (n1 > n2) ? n1 : n2;
    
    // use conditional (ternary) operator
    return 0; // placeholder return
}

// find Product function definition
large_int my_functions::find_product(const large_int n1, const large_int n2)
{
    return n1 * n2;
}

// FIXME5: define find_difference function declared inside my_functions namespace
int my_functions::find_difference(const large_int n1, const pos_int n2)
{
    return n1 - n2;
}

// return the value of second big_int subtracted 