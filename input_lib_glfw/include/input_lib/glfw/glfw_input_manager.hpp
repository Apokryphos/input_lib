#pragma once

#include "input_lib/glfw/glfw_gamepad.hpp"
#include "input_lib/glfw/glfw_keyboard.hpp"
#include "input_lib/glfw/glfw_mouse.hpp"
#include "input_lib/input_manager.hpp"

struct GLFWwindow;

namespace InputLib
{
class GlfwInputManager : public InputManager
{
    GlfwKeyboard mKeyboard;
    GlfwMouse mMouse;
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

void mouseButtonCallback(
    GLFWwindow* window,
    int button,
    int action,
    int mods
);

void mousePositionCallback(
    GLFWwindow* window,
    double xpos,
    double ypos
);

void registerGlfwCallbacks(GLFWwindow* window);

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
}
