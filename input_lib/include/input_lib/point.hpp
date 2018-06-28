#pragma once

namespace InputLib
{
struct Point
{
    int x;
    int y;

    Point(int x = 0, int y = 0)
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
