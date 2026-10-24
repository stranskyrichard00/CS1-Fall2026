#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.hpp"
using namespace std;


string checkHiss(const string& word);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;
    cout << checkHiss(word) << '\n';
    return 0;
}
