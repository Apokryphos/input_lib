#include "input_lib/glfw/glfw_mouse.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
ButtonState GlfwMouse::getButtonState(const unsigned button) const {
    return mButtonStateMap.getState(button, ButtonState::Up);
}

//  ----------------------------------------------------------------------------
ButtonStateMap& GlfwMouse::getButtonStateMap() {
    return mButtonStateMap;
}

//  ----------------------------------------------------------------------------
ButtonState GlfwMouse::getLeftButtonState() const {
    return getButtonState(Mouse::LEFT_BUTTON);
}

//  ----------------------------------------------------------------------------
ButtonState GlfwMouse::getMiddleState() const {
    return getButtonState(Mouse::MIDDLE_BUTTON);
}

//  ----------------------------------------------------------------------------
Point GlfwMouse::getPosition() {
    return mPosition;
}

//  ----------------------------------------------------------------------------
ButtonState GlfwMouse::getRightButtonState() const {
    return getButtonState(Mouse::RIGHT_BUTTON);
}

//  ----------------------------------------------------------------------------
bool GlfwMouse::isDown(const unsigned button) const {
    const ButtonState buttonState = getButtonState(button);
    return (
        buttonState == ButtonState::Down ||
        buttonState == ButtonState::Pressed
    );
}

//  ----------------------------------------------------------------------------
bool GlfwMouse::isPressed(const unsigned button) const {
    return getButtonState(button) == ButtonState::Pressed;
}

//  ----------------------------------------------------------------------------
void GlfwMouse::setPosition(float x, float y) {
    mPosition.x = x;
    mPosition.y = y;
}

//  ----------------------------------------------------------------------------
void GlfwMouse::update() {
    mButtonStateMap.clear();
}
}
