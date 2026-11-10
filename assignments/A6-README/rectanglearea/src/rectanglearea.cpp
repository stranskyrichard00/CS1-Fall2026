#include "rectanglearea.hpp"

#include <cmath>

using namespace std;

double rectangleArea(double x1, double y1, double x2, double y2) {
    return abs(x2 - x1) * abs(y2 - y1);
}