/*
Namespaces and Enum Type Lab

Updated by: [Rick Stransky]
Date: [9/30/26]
Instructor: [Dr. Ram Basnet ]
CS1 - Foundations of Computer Science

Program demonstrates the use of preprocessor directive, namespace and enum type.
*/

#include <cstdio>
#include <iostream>
#include "../includes/utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    char input;
    big_int num1;
    big_int num2;
    large_int sum;
    large_int prod;
    large_int larger;
    large_int difference;
    double area;

    OPERATION oper;
    clear();
    do
    {
        show_menu();
        cin >> input;
        oper = get_operation(input);
        switch (oper)
        {
        case ADD:
            cout << "Enter two whole numbers separated by space: ";
            cin >> num1 >> num2;
            sum = my_functions::find_sum(num1, num2);
            printf("%lld + %lld = %lld\n", num1, num2, sum);
            break;
        case MULTIPLY:
            cout << "Enter two whole numbers separated by space: ";
            cin >> num1 >> num2;
            prod = my_functions::find_product(num1, num2);
            printf("%lld * %lld = %lld\n", num1, num2, prod);
            break;
            // FIXME1: complete the rest of the cases to perform other operations defined in enum type
        case LARGER:
            cout << "Enter two whole numbers separated by space: ";
            cin >> num1 >> num2;
            larger = my_functions::find_larger(num1, num2);
            printf("%lld : %lld = %lld\n", num1, num2, larger);
            break;
        case SUBTRACT:
            cout << "Enter two whole numbers separated by space: ";
            cin >> num1 >> num2;
            difference = my_functions::find_difference(num1, num2);
            printf("%lld - %lld = %lld\n", num1, num2, difference);
            break;
        case AREAOFCIRC:
            cout << "Enter radius for circle: ";
            cin >> num1;
            area = my_functions::find_area_of_circle(num1);
            printf("%lld * %lld * %f = %f\n",num1, num1, my_functions::PI, area);
            break;

        case QUIT:
            break;
        }
    } while (oper != QUIT);

    cin.ignore(1000, '\n');
    cout << "Good bye! Enter to exit the program...";
    cin.get();
    return 0;
}