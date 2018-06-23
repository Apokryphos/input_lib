#include "input_lib/glfw/glfw_keyboard.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
void GlfwKeyboard::bind(const Action action, const Key key) {
    mActionMap.map(action, key);
}

//  ----------------------------------------------------------------------------
double GlfwKeyboard::getAnalogValue(const Action action) {
    const Key key = mActionMap.getValue(action);
    const KeyState keyState = mKeyState.getState(key, KeyState::Released);
    return keyStateToAnalogValue(keyState);
}

//  ----------------------------------------------------------------------------
bool GlfwKeyboard::getDigitalValue(const Action action) {
    const Key key = mActionMap.getValue(action);
    const KeyState keyState = mKeyState.getState(key, KeyState::Released);
    return keyStateToDigitalValue(keyState);
}

//  ----------------------------------------------------------------------------
bool GlfwKeyboard::isPressed(const Action action) {
    const Key key = mActionMap.getValue(action);
    const KeyState keyState = mKeyState.getState(key, KeyState::Released);
    return keyState == KeyState::Pressed;
}

//  ----------------------------------------------------------------------------
KeyStateMap& GlfwKeyboard::getKeyStateMap() {
    return mKeyState;
}
}
