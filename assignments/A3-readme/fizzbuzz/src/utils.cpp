#include <iostream>
#include <string>
using namespace std;

// function with conditionals for if the number is divisible by x or y with no remainder
string fizzbuzz(int number, int x, int y) {
        if(number % x == 0 && number % y ==0){
            return "FizzBuzz";

        } else if (number % x == 0){
            return "Fizz";
        } else if (number % y == 0) {
            return "Buzz";
        }
        return to_string(number);
        
    }
