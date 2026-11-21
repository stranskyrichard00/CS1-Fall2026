#include "num_system.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

using namespace std;

string fromDecimal(unsigned long long number, int base) {
    if (base != 2 && base != 8 && base != 16) {
        throw invalid_argument("Base must be 2, 8, or 16.");
    }

    const string digits = "0123456789ABCDEF";
    vector<char> remainders;

    // Repeated division produces digits in reverse order.
    do {
        remainders.push_back(digits[number % base]);
        number /= base;
    } while (number > 0);

    reverse(remainders.begin(), remainders.end());

    return string(remainders.begin(), remainders.end());
}

unsigned long long toDecimal(const string& number, int base) {
    if (base != 2 && base != 8 && base != 16) {
        throw invalid_argument("Base must be 2, 8, or 16.");
    }

    if (number.empty()) {
        throw invalid_argument("Enter at least one digit.");
    }

    const string digits = "0123456789ABCDEF";
    unsigned long long result = 0;
    const auto maximum = numeric_limits<unsigned long long>::max();

    for (char character : number) {
        // Accept lowercase hexadecimal letters too.
        if (character >= 'a' && character <= 'f') {
            character = character - 'a' + 'A';
        }

        size_t digit = digits.find(character);

        if (digit == string::npos ||
            digit >= static_cast<size_t>(base)) {
            throw invalid_argument("Invalid digit for the selected base.");
        }

        if (result > (maximum - digit) / base) {
            throw overflow_error("Number is too large.");
        }

        result = result * base + digit;
    }

    return result;
}