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
    ButtonState getButtonState(int button) const;
    ButtonState getLeftButtonState() const;
    ButtonState getMiddleState() const;
    ButtonState getRightButtonState() const;
    Point getPosition();
};
}
