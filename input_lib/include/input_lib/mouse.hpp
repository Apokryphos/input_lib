#pragma once

#include "input_lib/device.hpp"
#include "input_lib/point.hpp"

namespace InputLib
{
class Mouse : public Device
{
public:
    Mouse()
    : Device(DeviceType::Mouse) {
    }

    virtual ~Mouse() {}
    virtual ButtonState getButtonState(const unsigned button) const = 0;
    virtual ButtonState getLeftButtonState() const = 0;
    virtual ButtonState getMiddleState() const = 0;
    virtual Point getPosition() = 0;
    virtual ButtonState getRightButtonState() const = 0;
    virtual bool isDown(const unsigned button) = 0;
    virtual bool isPressed(const unsigned button) = 0;

    static const unsigned LEFT_BUTTON = 0;
    static const unsigned MIDDLE_BUTTON = 2;
    static const unsigned RIGHT_BUTTON = 1;
};
}
