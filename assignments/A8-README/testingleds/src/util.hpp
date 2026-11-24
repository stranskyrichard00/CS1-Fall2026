#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>

using namespace std;

struct Recording {
    long long time;
    int state;
};

long long firstOff(const vector<Recording>& recordings);

#endif