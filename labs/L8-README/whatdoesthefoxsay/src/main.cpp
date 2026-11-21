#include "util.hpp"

#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (testCases--) {
        string line;
        getline(cin, line);

        vector<string> recording;
        vector<string> knownSounds;
        string word;

        istringstream recordingInput(line);

        while (recordingInput >> word) {
            recording.push_back(word);
        }

        while (getline(cin, line) && line != "what does the fox say?") {
            istringstream animalInput(line);
            string animal, goes, sound;

            animalInput >> animal >> goes >> sound;
            knownSounds.push_back(sound);
        }

        vector<string> result = foxSounds(recording, knownSounds);

        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }

        cout << '\n';
    }

    return 0;
}