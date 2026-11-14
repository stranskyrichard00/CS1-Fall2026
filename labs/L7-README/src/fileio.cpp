#include "fileio.hpp"

#include <fstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

bool readNumbers(const string& filename, vector<int>& numbers) {
    ifstream input(filename);

    if (!input) {
        return false;
    }

    int count;

    if (!(input >> count) || count <= 0) {
        return false;
    }

    // Load into a temporary vector so failed reads preserve existing data.
    vector<int> loaded;

    for (int i = 0; i < count; ++i) {
        int number;

        if (!(input >> number)) {
            return false;
        }

        loaded.push_back(number);
    }

    // Reject extra values or other non-whitespace content.
    input >> ws;

    if (!input.eof()) {
        return false;
    }

    numbers.swap(loaded);
    return true;
}

int findMaximum(const vector<int>& numbers) {
    if (numbers.empty()) {
        throw invalid_argument("Cannot find maximum of empty data.");
    }

    int maximum = numbers[0];

    for (int number : numbers) {
        if (number > maximum) {
            maximum = number;
        }
    }

    return maximum;
}

int findMinimum(const vector<int>& numbers) {
    if (numbers.empty()) {
        throw invalid_argument("Cannot find minimum of empty data.");
    }

    int minimum = numbers[0];

    for (int number : numbers) {
        if (number < minimum) {
            minimum = number;
        }
    }

    return minimum;
}

long long calculateSum(const vector<int>& numbers) {
    long long sum = 0;

    for (int number : numbers) {
        sum += number;
    }

    return sum;
}

double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) {
        throw invalid_argument("Cannot average empty data.");
    }

    return static_cast<double>(calculateSum(numbers)) / numbers.size();
}

bool writeResults(const string& filename, const vector<int>& numbers) {
    if (numbers.empty()) {
        return false;
    }

    ofstream output(filename);

    if (!output) {
        return false;
    }

    output << "Count: " << numbers.size() << '\n';

    output << "Numbers:";

    for (int number : numbers) {
        output << ' ' << number;
    }

    output << '\n';
    output << "Maximum: " << findMaximum(numbers) << '\n';
    output << "Minimum: " << findMinimum(numbers) << '\n';
    output << "Sum: " << calculateSum(numbers) << '\n';
    output << fixed << setprecision(2);
    output << "Average: " << calculateAverage(numbers) << '\n';

    output.close();
    return !output.fail();
}

void deleteData(vector<int>& numbers) {
    numbers.clear();
}