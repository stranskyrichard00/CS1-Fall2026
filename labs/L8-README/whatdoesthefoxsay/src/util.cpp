#include "util.hpp"

#include <algorithm>

using namespace std;

vector<string> foxSounds(
    const vector<string>& recording,
    const vector<string>& knownSounds
) {
    vector<string> result;

    for (const string& sound : recording) {
        if (find(knownSounds.begin(), knownSounds.end(), sound)
            == knownSounds.end()) {
            result.push_back(sound);
        }
    }

    return result;
}