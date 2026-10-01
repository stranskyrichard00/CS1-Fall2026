//  Updated by: Rick Stransky
//  Date: 9/30/26
//  Program demonstrates the use of pointers, preprocessor directive,
//  namespace, and enum type.

#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include "../includes/utils.h"

using namespace std;
using namespace my_space;

int main(int argc, char *argv[])
{
    char *input;
    big_int *num1;                  // a pointer variable to point to big_int data
    num1 = new big_int;             // allocate memory in heap and store the address in num1
    big_int *num2 = new big_int;    // declare num2 as a dynamic variable
    large_int *sum = new large_int; // declare sum as a dynamic variable
    large_int *prod = new large_int;
    // FIXME0 - create a dynamic memory to store a char and store its address in input pointer
    input = new char;
    // FIXME1 - declare dynamic variables to store difference and larger values
    int *difference = new int;

    int *larger = new int;
    // Must use these variables to store the returned values from functions

    OPERATION oper;

    // FIXME2: Add do... while loop to continue the program until the user wants to quit
   do{

    // FIXME3: call clear function defined above to clear the screen
    clear();


    show_menu();
    cin >> *input;
    oper = get_operation(*input);
    switch (oper)
    {
    case ADD:
        cout << "Enter two whole numbers separated by space: ";
        // store the data by dereferencing pointers
        cin >> *num1 >> *num2 >> ws;
        // passing pointers to find_sum function
        *sum = find_sum(num1, num2);
        printf("%lld + %lld = %lld\n", *num1, *num2, *sum);
        break;
    case MULTIPLY:
        cout << "Enter two whole numbers separated by space: ";
        // store the data by dereferencing pointers
        cin >> *num1 >> *num2 >> ws;
        // passing dereferences (actural addresses) of num1 and num2
        *prod = find_product(*num1, *num2);
        printf("%lld * %lld = %lld\n", *num1, *num2, *prod);
        break;
    // FIXME4: complete the rest of the cases to perform other operations
    case SUBTRACT:
        cout << "Enter two whole numbers seperated by space: ";
        //store the data by dereferencing pointers
        cin >> *num1 >> *num2 >> ws;
        *difference = find_difference(*num1, *num2);
        printf("%lld - %lld = %d\n", *num1, *num2, *difference);
        break;
    case LARGER:
        cout << "Enter two whole numbers seperate by space: ";
        //store the data by dereferencing pointers
        cin >> *num1 >> *num2 >> ws;
        *larger = find_larger(num1, num2);
        printf("%lld > %lld = %d\n", *num1, *num2, *larger);
        break;
        default:
        break;
    }
    }while (oper != QUIT);
    
   
    // delete/dzallocate/free memory occupied by all the dynamic variables
    delete num1;
    delete num2;
    delete sum;
    delete prod;
    // FIXME5: delete other dynamic variables created above
    delete difference;
    delete larger;
    cin.ignore(1000, '\n');
    cout << "Good bye! Enter to exit the program...";
    cin.get();
    return 0;
}