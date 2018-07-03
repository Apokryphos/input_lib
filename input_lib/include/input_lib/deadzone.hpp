#pragma once

#include "input_lib/point.hpp"
#include <cmath>
#include <functional>

namespace InputLib
{
//  Deadzone filter functions for a single value
typedef std::function<float(
    const float deadzone,
    const float value
)> DeadzoneFloatFilter;

//  Deadzone filter functions for two values (XY)
typedef std::function<Point(
    const float deadzone,
    const float x,
    const float y
)> DeadzonePointFilter;

//  ----------------------------------------------------------------------------
static float noDeadzone(const float deadzone, const float value) {
    return value;
}

//  ----------------------------------------------------------------------------
static float basicDeadzone(const float deadzone, const float value) {
    if (std::abs(value) >= deadzone) {
        return value;
    }

    return 0.0f;
}

//  ----------------------------------------------------------------------------
static Point noDeadzone(const float deadzone, const float x, const float y) {
    return Point(x, y);
}

//  ----------------------------------------------------------------------------
static Point radialDeadzone(
    const float deadzone,
    const float x,
    const float y
) {
    //  Calculate vector length
    const double length = std::sqrt(x * x + y * y);

    //  Normalize if needed
    if (length > 1.0f) {
        const float nx = x / length;
        const float ny = y / length;
        return radialDeadzone(deadzone, nx, ny);
    }

    if (length >= deadzone) {
        return Point(x, y);
    }

    return Point(0.0f, 0.0f);
}
}
