#pragma once

#include "input_lib/button.hpp"
#include "input_lib/button_state.hpp"
#include "input_lib/device.hpp"

namespace InputLib
{
class Gamepad : public InputDevice
{
public:
    virtual ~Gamepad() {}
    virtual float getAxisValue(const unsigned axis) const = 0;
    virtual ButtonState getButtonState(const Button button) const = 0;
    virtual bool isConnected() = 0;
    virtual bool isDown(const Button button) = 0;
    virtual bool isPressed(const Button button) = 0;
};
}
