#ifndef NUM_SYSTEM_HPP
#define NUM_SYSTEM_HPP

#include <string>

using namespace std;

string fromDecimal(unsigned long long number, int base);
unsigned long long toDecimal(const string& number, int base);

#endif