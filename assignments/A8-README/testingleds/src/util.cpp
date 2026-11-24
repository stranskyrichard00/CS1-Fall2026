#include "util.hpp"

using namespace std;

long long firstOff(const vector<Recording>& recordings) {
    long long earliest = -1;

    for (const Recording& recording : recordings) {
        // Pointer to the current recording.
        const Recording* current = &recording;

        if (current->state == 0 &&
            (earliest == -1 || current->time < earliest)) {
            earliest = current->time;
        }
    }

    return earliest;
}