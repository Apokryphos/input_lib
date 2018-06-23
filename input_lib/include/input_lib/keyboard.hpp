#pragma once

#include "input_lib/action.hpp"
#include "input_lib/device.hpp"

namespace InputLib
{
class Keyboard : public InputDevice
{
public:
    virtual ~Keyboard() {}
    virtual void bind(const Action action, const Key key) = 0;
    virtual double getAnalogValue(const Action action) = 0;
    virtual bool getDigitalValue(const Action action) = 0;
    virtual bool isPressed(const Action action) = 0;
};
}
