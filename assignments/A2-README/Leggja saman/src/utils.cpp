#include "headers.hpp"

namespace parking {
    long long totalCars(const long long* parkedCars) {
        return parkedCars[static_cast<int>(Driver::Arnar)]
             + parkedCars[static_cast<int>(Driver::Hannes)];
    }
}