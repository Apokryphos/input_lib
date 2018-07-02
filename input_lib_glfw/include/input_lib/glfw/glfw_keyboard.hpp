#pragma once

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
    KeyStateMap mKeyState;

public:
    virtual KeyState getKeyState(const Key key) const override;
    KeyStateMap& getKeyStateMap();
    virtual const std::string& getName() const override;
    virtual bool isDown(const Key key) const override;
    virtual bool isPressed(const Key key) const override;
};
}
