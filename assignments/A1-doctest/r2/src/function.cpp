#include <iostream>
#include "r2.hpp"
using namespace std;

//fruitful function to add r2 twice to find the missing value by minusing the first!
int r2(int first, int mean){

    int missing = mean + mean - first;
    return missing;
    
}