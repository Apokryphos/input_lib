#include "input_lib/bimap.hpp"
#include "input_lib/glfw/glfw_input_manager.hpp"
#include "input_lib/glfw/glfw_key_map.hpp"
#include <GLFW/glfw3.h>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

namespace InputLib
{
static GlfwInputManager* sInputManager;
static Bimap<Key, int> sKeyMap;

//  ----------------------------------------------------------------------------
void joystickCallback(int joy, int event) {
    auto& gamepad = static_cast<GlfwGamepad&>(sInputManager->getGamepad(joy));
    if (event == GLFW_CONNECTED) {
        std::cout << "Joystick " << joy << " connected." << std::endl;
    } else {
        std::cout << "Joystick " << joy << " disconnected." << std::endl;
    }
}

//  ----------------------------------------------------------------------------
static void updateButtonState(int glfwButton, const ButtonState buttonState) {
    auto& mouse = sInputManager->getMouse();
    auto& buttonStateMap = static_cast<GlfwMouse&>(mouse).getButtonStateMap();
    buttonStateMap.setState(glfwButton, buttonState);
}

//  ----------------------------------------------------------------------------
static void updateKeyState(int glfwKey, const KeyState keyState) {
    auto& keyboard = sInputManager->getKeyboard();
    auto& keyStateMap = static_cast<GlfwKeyboard&>(keyboard).getKeyStateMap();
    const Key key = sKeyMap.getKey(glfwKey, Key::None);
    keyStateMap.setState(key, keyState);
}

//  ----------------------------------------------------------------------------
void keyboardCallback(
    GLFWwindow* window,
    int key,
    [[maybe_unused]] int scancode,
    int action,
    [[maybe_unused]] int mods) {
    if (sInputManager == nullptr) {
        return;
    }

    switch (action) {
        case GLFW_PRESS:
            updateKeyState(key, KeyState::Pressed);
            break;

        case GLFW_REPEAT:
            updateKeyState(key, KeyState::Down);
            break;

        case GLFW_RELEASE:
            updateKeyState(key, KeyState::Released);
            break;
    }
}

//  ----------------------------------------------------------------------------
void mouseButtonCallback(
    GLFWwindow* window,
    int button,
    int action,
    int mods
) {
    switch (action) {
        case GLFW_PRESS:
            updateButtonState(button, ButtonState::Pressed);
            break;

        case GLFW_REPEAT:
            updateButtonState(button, ButtonState::Down);
            break;

        case GLFW_RELEASE:
            updateButtonState(button, ButtonState::Released);
            break;
    }
}

//  ----------------------------------------------------------------------------
void mousePositionCallback(
    GLFWwindow* window,
    double xpos,
    double ypos
) {
    if (sInputManager == nullptr) {
        return;
    }

    auto& mouse = static_cast<GlfwMouse&>(sInputManager->getMouse());
    mouse.setPosition(xpos, ypos);
}

//  ----------------------------------------------------------------------------
GlfwInputManager::GlfwInputManager() {
    assert(sInputManager == nullptr);
    sInputManager = this;
    initializeGlfwKeyMap(sKeyMap);
}

//  ----------------------------------------------------------------------------
GlfwInputManager::~GlfwInputManager() {
    sInputManager = nullptr;
}

//  ----------------------------------------------------------------------------
Gamepad& GlfwInputManager::getGamepad(const unsigned index) {
    if (mGamepads.find(index) == mGamepads.end())  {
        mGamepads.try_emplace(index, index);
    }

    return mGamepads.at(index);
}

//  ----------------------------------------------------------------------------
Mouse& GlfwInputManager::getMouse() {
    return mMouse;
}

//  ----------------------------------------------------------------------------
Keyboard& GlfwInputManager::getKeyboard() {
    return mKeyboard;
}

//  ----------------------------------------------------------------------------
void GlfwInputManager::update() {
    //  Update Pressed and Released states to Down and Up
    auto& keyStateMap = mKeyboard.getKeyStateMap();
    keyStateMap.update();

    //  Update Pressed and Released states to Down and Up
    auto& buttonStateMap = mMouse.getButtonStateMap();
    buttonStateMap.update();

    glfwPollEvents();

    //  Update gamepads
    for (int j = 0; j < GLFW_JOYSTICK_LAST; ++j) {
        if (glfwJoystickPresent(j) == GLFW_TRUE) {
            auto& gamepad = static_cast<GlfwGamepad&>(getGamepad(j));
            gamepad.update();
        }
    }
}
}
