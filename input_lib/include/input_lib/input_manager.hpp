#pragma once

#include "gamepad.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"

namespace InputLib
{
class InputManager
{
public:
    InputManager() {}
    virtual ~InputManager() {}
    InputManager(const InputManager&) = delete;
    void operator=(const InputManager&) = delete;
    virtual Mouse& getMouse() = 0;
    virtual Gamepad& getGamepad(unsigned index) = 0;
    virtual Keyboard& getKeyboard() = 0;
    virtual void update() = 0;
};
}
