#include "input_lib/glfw/glfw_gamepad.hpp"
#include <GLFW/glfw3.h>
#include <cmath>

namespace InputLib
{
//  ----------------------------------------------------------------------------
static float applyDeadzone(const float value, const float deadzone) {
    return std::abs(value) >= deadzone ? value : 0.0f;
}

//  ----------------------------------------------------------------------------
GlfwGamepad::GlfwGamepad(int index)
: mIndex(index),
  mDeadzone(0.2f) {
}

//  ----------------------------------------------------------------------------
float GlfwGamepad::getAxisValue(const unsigned axis) const {
    const auto& find = mAxisMap.find(axis);

    if (find == mAxisMap.end()) {
        return 0.0f;
    }

    return applyDeadzone(find->second, mDeadzone);
}

//  ----------------------------------------------------------------------------
ButtonState GlfwGamepad::getButtonState(const unsigned button) const {
    return mButtonStateMap.getState(button, ButtonState::Up);
}

//  ----------------------------------------------------------------------------
bool GlfwGamepad::isConnected() {
    return glfwJoystickPresent(mIndex) == GLFW_TRUE;
}

//  ----------------------------------------------------------------------------
bool GlfwGamepad::isDown(const unsigned button) {
    const ButtonState buttonState = mButtonStateMap.getState(
        button,
        ButtonState::Up
    );

    return (
        buttonState == ButtonState::Down ||
        buttonState == ButtonState::Pressed
    );
}

//  ----------------------------------------------------------------------------
bool GlfwGamepad::isPressed(const unsigned button) {
    return mButtonStateMap.getState(
        button,
        ButtonState::Up
    ) == ButtonState::Pressed;
}

//  ----------------------------------------------------------------------------
void GlfwGamepad::update() {
    if (!glfwJoystickPresent(mIndex)) {
        mButtonStateMap.clear();
        return;
    }

    mButtonStateMap.update();

    int buttonCount;
    const unsigned char* buttons = glfwGetJoystickButtons(mIndex, &buttonCount);

    if (buttons == NULL || buttonCount == 0) {
        return;
    }

    for (unsigned b = 0; b < buttonCount; ++b) {
        const int glfwButtonState = buttons[b];

        ButtonState buttonState;
        switch (glfwButtonState) {
            case GLFW_PRESS:
                buttonState = ButtonState::Pressed;
                break;

            case GLFW_RELEASE:
                buttonState = ButtonState::Released;
                break;
        }

        mButtonStateMap.setState(b, buttonState);
    }

    //  Update each axis
    int axisCount;
    const float* axes = glfwGetJoystickAxes(mIndex, &axisCount);
    for (unsigned a = 0; a < axisCount; ++a) {
        mAxisMap[a] = axes[a];
    }
}
}
