#pragma once

#include "input_lib/action.hpp"
#include "input_lib/device.hpp"

namespace InputLib
{
enum class MouseAxis
{
    X,
    Y,
    Wheel,
};

enum class MouseButton
{
    Left,
    Right,
    Middle,
};

struct Point
{
    int x;
    int y;
};

class Mouse : public InputDevice
{
public:
    void bind(const Action action, const MouseAxis axis);
    void bind(const Action action, const MouseButton button);
    double getAnalogValue(const Action action);
    bool getDigitalValue(const Action action);
    Point getPosition();
};
}
