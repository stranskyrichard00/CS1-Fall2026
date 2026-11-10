#include "titlecost.hpp"

#include <algorithm>

using namespace std;

double transmissionCost(const string& title, double cap) {
    return min(static_cast<double>(title.length()), cap);
}