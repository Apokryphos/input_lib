#pragma once

namespace InputLib
{
enum class ButtonState
{
    Up,
    Pressed,
    Down,
    Released,
};

//  ----------------------------------------------------------------------------
inline double buttonStateToAnalogValue(const ButtonState buttonState) {
    switch (buttonState) {
        case ButtonState::Down:
        case ButtonState::Pressed:
            return 1.0;

        case ButtonState::Up:
        case ButtonState::Released:
        default:
            return 0.0;
    }
}

//  ----------------------------------------------------------------------------
inline double buttonStateToDigitalValue(const ButtonState buttonState) {
    switch (buttonState) {
        case ButtonState::Down:
        case ButtonState::Pressed:
            return true;

        case ButtonState::Up:
        case ButtonState::Released:
        default:
            return false;
    }
}
}
