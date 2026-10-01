#pragma once

// macro function
#ifdef _WIN32
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

// user-defined enumerated type: OPERATION
// FIXME2: add more operations as needed
enum OPERATION
{
    ADD,
    MULTIPLY,
    SUBTRACT,
    LARGER,
    AREAOFCIRC,
    QUIT
};

// C++ way of defining type alias
using big_int = long long int;
using pos_int = unsigned int;

// C way of defining type alias
typedef long long int large_int;
// both large_int and big_int are alias to "long long int" type

// declare my_functions namespace and header file contents
namespace my_functions
{
    // function prototypes defined within the namespace
    big_int find_sum(const big_int, const big_int);
    big_int find_larger(const big_int, const big_int);
    large_int find_product(const large_int, const large_int);
    int find_difference(const large_int, const pos_int);
    const double PI = 3.141592653589793;
    const double EPSILON = 0.0000001;
    double find_area_of_circle(const double);
}

void show_menu(void);
OPERATION get_operation(char);