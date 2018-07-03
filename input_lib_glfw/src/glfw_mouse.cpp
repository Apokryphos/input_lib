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
ButtonState GlfwMouse::getMiddleButtonState() const {
    return getButtonState(Mouse::MIDDLE_BUTTON);
}

//  ----------------------------------------------------------------------------
const std::string& GlfwMouse::getName() const {
    static const std::string name = "Mouse";
    return name;
}

//  ----------------------------------------------------------------------------
Coord GlfwMouse::getPosition() {
    return mPosition;
}

//  ----------------------------------------------------------------------------
ButtonState GlfwMouse::getRightButtonState() const {
    return getButtonState(Mouse::RIGHT_BUTTON);
}

//  ----------------------------------------------------------------------------
float GlfwMouse::getScroll() const {
    return mScroll;
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
void GlfwMouse::setScroll(float scroll) {
    mScroll = scroll;
}

//  ----------------------------------------------------------------------------
void GlfwMouse::update() {
    mButtonStateMap.update();

    mScroll = 0;
}
}
