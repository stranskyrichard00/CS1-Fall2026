#include <iostream>
#include "header.hpp"
using namespace std;

// function will always return the greater value of the two variables
int greater_function(int a, int b){
    if (a > b) {
        return a;
    }
    return b;
}
// function will return the lesser value of the two variables
int lesser_function(int a, int b){
    if (a < b) {
        return a;
    }
    return b;
}
