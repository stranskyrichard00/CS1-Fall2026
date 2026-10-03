#include <iostream>
#include <memory>
#include <string>
#include "header.hpp"
using namespace std;

int main() {
    auto word = make_unique<string>();
    cin >> *word;

    cout << repeated::repeatWord(
        *word, repeated::Count::Three
    ) << '\n';

    return 0;
}