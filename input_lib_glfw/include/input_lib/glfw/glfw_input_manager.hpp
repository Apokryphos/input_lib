#pragma once

#include "input_lib/glfw/glfw_keyboard.hpp"
#include "input_lib/input_manager.hpp"

struct GLFWwindow;

namespace InputLib
{
class GlfwInputManager : public InputManager
{
    GlfwKeyboard mKeyboard;

public:
    GlfwInputManager();
    virtual ~GlfwInputManager();
    virtual Mouse& getMouse() override;
    virtual Keyboard& getKeyboard() override;
    virtual void update() override;
};

void keyboardCallback(
    GLFWwindow* window,
    int key,
    int scancode,
    int action,
    int mods
);
}
