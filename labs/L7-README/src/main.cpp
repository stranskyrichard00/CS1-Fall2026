#include "fileio.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "\nFileIO Menu\n"
         << "1. Read data from a file\n"
         << "2. Display data\n"
         << "3. Find maximum and minimum\n"
         << "4. Calculate sum and average\n"
         << "5. Write results to a file\n"
         << "6. Delete loaded data\n"
         << "0. Exit\n"
         << "Enter your choice: ";
}

int main() {
    vector<int> numbers;
    string line;

    while (true) {
        displayMenu();

        if (!getline(cin, line)) {
            break;
        }

        istringstream choiceInput(line);
        int choice;
        string extra;

        if (!(choiceInput >> choice) || (choiceInput >> extra)) {
            cout << "Please enter a valid menu number.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice == 1) {
            string filename;

            cout << "Input filename: ";

            if (!getline(cin, filename)) {
                break;
            }

            if (readNumbers(filename, numbers)) {
                cout << "Loaded " << numbers.size() << " integers.\n";
            } else {
                cout << "Could not read the file. Use a positive count "
                     << "followed by exactly that many integers.\n";
            }

            continue;
        }

        if (choice == 6) {
            deleteData(numbers);
            cout << "Loaded data deleted. Input files were preserved.\n";
            continue;
        }

        if (choice < 2 || choice > 5) {
            cout << "Invalid option. Choose 0 through 6.\n";
            continue;
        }

        if (numbers.empty()) {
            cout << "No data loaded. Choose option 1 first.\n";
            continue;
        }

        switch (choice) {
            case 2:
                cout << "Numbers:";

                for (int number : numbers) {
                    cout << ' ' << number;
                }

                cout << '\n';
                break;

            case 3:
                cout << "Maximum: " << findMaximum(numbers) << '\n';
                cout << "Minimum: " << findMinimum(numbers) << '\n';
                break;

            case 4:
                cout << "Sum: " << calculateSum(numbers) << '\n';
                cout << fixed << setprecision(2);
                cout << "Average: " << calculateAverage(numbers) << '\n';
                break;

            case 5: {
                string filename;

                cout << "Output filename: ";

                if (!getline(cin, filename)) {
                    return 0;
                }

                if (writeResults(filename, numbers)) {
                    cout << "Results written to " << filename << '\n';
                } else {
                    cout << "Could not write the output file.\n";
                }

                break;
            }
        }
    }

    return 0;
}