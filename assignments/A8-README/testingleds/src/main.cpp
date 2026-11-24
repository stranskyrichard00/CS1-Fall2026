#include "util.hpp"

#include <iostream>

using namespace std;


int main() {
    int count;
    cin >> count;

    vector<Recording> recordings(count);

    for (Recording& recording : recordings) {
        cin >> recording.time >> recording.state;
    }

    cout << firstOff(recordings) << '\n';

    return 0;
}