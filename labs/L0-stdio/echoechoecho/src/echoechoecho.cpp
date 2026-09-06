/*
    StdIO Lab
    Kattis - Echo Echo Echo Problem

    Updated By: Rick Stransky
    Date: 09/05/2026
    CSCI 111

    This program prints the input word 3 times.

    Algorithm steps:
    1. Declare a string variable to store input data
    3. Read and store the input data into the variable
    3. Print the word 3 times separated by space
*/

#include <iostream>
// FIXME1: include string library
#include <string>

// FIXME2: use namespace standard
using namespace std;

int main()
{
    // FIXME3: Uncomment the following two lines
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

    // FIXME4: algorithm step 1
    string echo_word;
    // FIXME5: algorithm step 2
    getline(cin, echo_word);
    // FIXME6: algorithm step 3
    cout << echo_word << " " << echo_word << " " << echo_word << endl;
    return 0;
}