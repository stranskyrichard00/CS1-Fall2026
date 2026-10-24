#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.hpp"
using namespace std;



string checkHiss(const string& word) {
    return word.find("ss") != string::npos ? "hiss" : "no hiss";
}