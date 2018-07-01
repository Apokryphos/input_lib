#pragma once

#include "input_lib/device.hpp"
#include "input_lib/key.hpp"
#include "input_lib/key_state.hpp"

namespace InputLib
{
class Keyboard : public Device
{
public:
    Keyboard()
    : Device(DeviceType::Keyboard) {
    }

    virtual ~Keyboard() {}
    virtual KeyState getKeyState(const Key key) const = 0;
    virtual bool isDown(const Key key) const = 0;
    virtual bool isPressed(const Key key) const = 0;
};
}
