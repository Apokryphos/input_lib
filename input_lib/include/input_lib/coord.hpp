#pragma once

namespace InputLib
{
struct Coord
{
    int x;
    int y;

    Coord(int x = 0, int y = 0)
    : x(x), y(y) {
    }
};

inline bool operator==(const Coord& p1, const Coord& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

inline bool operator!=(const Coord& p1, const Coord& p2) {
    return p1.x != p2.x || p1.y != p2.y;
}
}
