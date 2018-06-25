#pragma once

#include "gamepad.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"

namespace InputLib
{
class InputManager
{
public:
    virtual Mouse& getMouse() = 0;
    virtual Gamepad& getGamepad(unsigned index) = 0;
    virtual Keyboard& getKeyboard() = 0;
    virtual void update() = 0;
};
}
