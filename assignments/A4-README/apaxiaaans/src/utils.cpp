#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;

string compactName(string name) {
    string result = "";

    const char* ptr = name.c_str();

    for (size_t i = 0; i < name.length(); i++) {
        if (i == 0 || ptr[i] != ptr[i - 1]) {
            result += ptr[i];
        }
    }


    return result;
}