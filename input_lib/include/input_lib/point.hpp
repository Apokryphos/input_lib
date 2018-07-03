#pragma once

namespace InputLib
{
struct Point
{
    float x;
    float y;

    Point(float x = 0, float y = 0)
    : x(x), y(y) {
    }
};

inline bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

inline bool operator!=(const Point& p1, const Point& p2) {
    return p1.x != p2.x || p1.y != p2.y;
}
}
