#include "main.h"

using namespace std;

string makeNice(const string& numbers) {
    // These lists already reduce to one element.
    if (numbers.length() == 1 || numbers == "22") {
        return numbers;
    }

    // Make each consecutive group of 2s have an even length.
    string pairedTwos;
    int countTwos = 0;

    for (char number : numbers) {
        if (number == '2') {
            countTwos++;
        }
        else {
            if (countTwos % 2 != 0) {
                pairedTwos += '2';
            }

            countTwos = 0;
        }

        pairedTwos += number;
    }

    // Handle a group of 2s at the end.
    if (countTwos % 2 != 0) {
        pairedTwos += '2';
    }

    // Make each section between 8s sum to a multiple of 8.
    string answer;
    int sectionSum = 0;
    int total = 0;

    for (char number : pairedTwos) {
        if (number == '8') {
            if (sectionSum % 8 != 0) {
                answer += '4';
                total += 4;
            }

            sectionSum = 0;
        }
        else {
            sectionSum += number - '0';
        }

        answer += number;
        total += number - '0';
    }

    // Handle the section after the final 8.
    if (sectionSum % 8 != 0) {
        answer += '4';
        total += 4;
    }

    // Find the smallest power of two at least as large as total.
    int target = 1;

    while (target < total) {
        target *= 2;
    }

    // Append 8s until the total reaches that power of two.
    while (total < target) {
        answer += '8';
        total += 8;
    }

    return answer;
}