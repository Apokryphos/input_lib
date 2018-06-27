#pragma once

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

class Mouse : public Device
{
public:
    Mouse()
    : Device(DeviceType::Mouse) {
    }

    virtual ~Mouse() {}
    ButtonState getButtonState(int button) const;
    ButtonState getLeftButtonState() const;
    ButtonState getMiddleState() const;
    ButtonState getRightButtonState() const;
    Point getPosition();
};
}
