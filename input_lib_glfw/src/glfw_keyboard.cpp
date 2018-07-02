#include "input_lib/glfw/glfw_keyboard.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
KeyState GlfwKeyboard::getKeyState(const Key key) const {
    return mKeyState.getState(key, KeyState::Up);
}

//  ----------------------------------------------------------------------------
const std::string& GlfwKeyboard::getName() const {
    static const std::string name = "Keyboard";
    return name;
}

//  ----------------------------------------------------------------------------
bool GlfwKeyboard::isDown(const Key key) const {
    const KeyState keyState = mKeyState.getState(key, KeyState::Released);
    return (
        keyState == KeyState::Down ||
        keyState == KeyState::Pressed
    );
}

//  ----------------------------------------------------------------------------
bool GlfwKeyboard::isPressed(const Key key) const {
    const KeyState keyState = mKeyState.getState(key, KeyState::Released);
    return keyState == KeyState::Pressed;
}

//  ----------------------------------------------------------------------------
KeyStateMap& GlfwKeyboard::getKeyStateMap() {
    return mKeyState;
}
}
