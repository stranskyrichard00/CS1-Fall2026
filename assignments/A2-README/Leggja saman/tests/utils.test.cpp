#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/headers.hpp"

TEST_CASE("totalCars adds both parked car counts") {
    long long parkedCars[] = {4, 3};
    CHECK(parking::totalCars(parkedCars) == 7);

    long long moreCars[] = {11, 31};
    CHECK(parking::totalCars(moreCars) == 42);
}