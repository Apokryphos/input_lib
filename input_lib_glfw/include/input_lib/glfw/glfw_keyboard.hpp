#pragma once

#include "input_lib/action.hpp"
#include "input_lib/bimap.hpp"
#include "input_lib/device.hpp"
#include "input_lib/key.hpp"
#include "input_lib/keyboard.hpp"
#include "input_lib/key_state.hpp"
#include "input_lib/key_state_map.hpp"
#include <map>

namespace InputLib
{
class GlfwKeyboard : public Keyboard
{
    Bimap<Action, Key> mActionMap;
    KeyStateMap mKeyState;


public:
    virtual void bind(const Action action, const Key key) override;
    virtual double getAnalogValue(const Action action) override;
    virtual bool getDigitalValue(const Action action) override;
    KeyStateMap& getKeyStateMap();
    virtual bool isPressed(const Action action) override;
};
}
