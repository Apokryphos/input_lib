#pragma once

namespace InputLib
{
enum class KeyState
{
    Up,
    Pressed,
    Down,
    Released,
};

//  ----------------------------------------------------------------------------
inline double keyStateToAnalogValue(const KeyState keyState) {
    switch (keyState) {
        case KeyState::Down:
        case KeyState::Pressed:
            return 1.0;

        case KeyState::Up:
        case KeyState::Released:
        default:
            return 0.0;
    }
}

//  ----------------------------------------------------------------------------
inline double keyStateToDigitalValue(const KeyState keyState) {
    switch (keyState) {
        case KeyState::Down:
        case KeyState::Pressed:
            return true;

        case KeyState::Up:
        case KeyState::Released:
        default:
            return false;
    }
}
}
