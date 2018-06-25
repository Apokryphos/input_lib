#pragma once

#include "input_lib/glfw/glfw_gamepad.hpp"
#include "input_lib/glfw/glfw_keyboard.hpp"
#include "input_lib/input_manager.hpp"

struct GLFWwindow;

namespace InputLib
{
class GlfwInputManager : public InputManager
{
    GlfwKeyboard mKeyboard;
    std::map<int, GlfwGamepad> mGamepads;

public:
    GlfwInputManager();
    virtual ~GlfwInputManager();
    virtual Gamepad& getGamepad(const unsigned index) override;
    virtual Mouse& getMouse() override;
    virtual Keyboard& getKeyboard() override;
    virtual void update() override;
};

void joystickCallback(int joy, int event);

void keyboardCallback(
    GLFWwindow* window,
    int key,
    int scancode,
    int action,
    int mods
);
}
