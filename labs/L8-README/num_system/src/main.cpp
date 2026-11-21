#include "num_system.hpp"

#include <exception>
#include <iostream>
#include <sstream>

using namespace std;


int main() {
    string line;

    while (true) {
        cout << "\nNumber System Menu\n"
             << "1. Decimal to binary\n"
             << "2. Decimal to octal\n"
             << "3. Decimal to hexadecimal\n"
             << "4. Binary to decimal\n"
             << "5. Octal to decimal\n"
             << "6. Hexadecimal to decimal\n"
             << "0. Exit\n"
             << "Choice: ";

        if (!getline(cin, line)) break;

        istringstream menuInput(line);
        int choice;
        string extra;

        if (!(menuInput >> choice) || (menuInput >> extra) ||
            choice < 0 || choice > 6) {
            cout << "Enter a choice from 0 to 6.\n";
            continue;
        }

        if (choice == 0) break;

        cout << "Number: ";
        string number;

        if (!getline(cin, number)) break;

        int bases[] = {2, 8, 16};
        int base = bases[(choice - 1) % 3];

        try {
            if (choice <= 3) {
                // Validate decimal input before using stoull.
                if (number.empty() ||
                    number.find_first_not_of("0123456789")
                        != string::npos) {
                    cout << "Enter a nonnegative integer.\n";
                    continue;
                }

                unsigned long long decimal = stoull(number);
                string answer = fromDecimal(decimal, base);
                cout << "Result: " << answer << '\n';
            } else {
                unsigned long long answer = toDecimal(number, base);
                cout << "Result: " << answer << '\n';
            }
        } catch (const exception& error) {
            cout << "Conversion failed: " << error.what() << '\n';
        }
    }

    return 0;
}