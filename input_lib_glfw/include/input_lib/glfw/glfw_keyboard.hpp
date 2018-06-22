#pragma once

#include "input_lib/action.hpp"
#include "input_lib/device.hpp"
#include "input_lib/key.hpp"
#include "input_lib/keyboard.hpp"
#include "input_lib/key_state.hpp"
#include "input_lib/map.hpp"

namespace InputLib
{
class GlfwKeyboard : public Keyboard
{
    Map<Action, Key> mActionMap;
    Map<Key, KeyState> mKeyState;


public:
    virtual void bind(const Action action, const Key key) override;
    virtual double getAnalogValue(const Action action) override;
    virtual bool getDigitalValue(const Action action) override;
    Map<Key, KeyState>& getKeyState();
};
}
