#include <iostream>
#include <string>
#include "header.hpp"
using namespace std;


namespace repeated {
    string repeatWord(const string& word, Count count) {
        string result = word;

        for (int i = 1; i < static_cast<int>(count); ++i) {
            result += ' ';
            result += word;
        }

        return result;
    }
}