#pragma once

namespace parking {
    enum class Driver : int {
        Arnar = 0,
        Hannes = 1
    };

    long long totalCars(const long long* parkedCars);
}