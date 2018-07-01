#pragma once

#include "input_lib/gamepad_axis.hpp"
#include "input_lib/gamepad_button.hpp"
#include "input_lib/key_state.hpp"
#include "input_lib/point.hpp"
#include <stdexcept>
#include <string>

namespace InputLib
{
inline static std::string to_string(const GamepadAxis axis) {
    switch (axis) {
        case GamepadAxis::Axis1:
            return "Axis 1";
        case GamepadAxis::Axis2:
            return "Axis 2";
        case GamepadAxis::Axis3:
            return "Axis 3";
        case GamepadAxis::Axis4:
            return "Axis 4";
        case GamepadAxis::Axis5:
            return "Axis 5";
        case GamepadAxis::Axis6:
            return "Axis 6";
        default:
            throw std::runtime_error("Case not implemented.");
    }
}

inline static std::string to_string(const GamepadButton button) {
    switch (button) {
        case GamepadButton::Button1:
            return "Button 1";
        case GamepadButton::Button2:
            return "Button 2";
        case GamepadButton::Button3:
            return "Button 3";
        case GamepadButton::Button4:
            return "Button 4";
        case GamepadButton::Button5:
            return "Button 5";
        case GamepadButton::Button6:
            return "Button 6";
        case GamepadButton::Button7:
            return "Button 7";
        case GamepadButton::Button8:
            return "Button 8";
        case GamepadButton::Button9:
            return "Button 9";
        case GamepadButton::Button10:
            return "Button 10";
        case GamepadButton::Button11:
            return "Button 11";
        case GamepadButton::Button12:
            return "Button 12";
        case GamepadButton::Button13:
            return "Button 13";
        case GamepadButton::Button14:
            return "Button 14";
        case GamepadButton::Button15:
            return "Button 15";
        default:
            throw std::runtime_error("Case not implemented.");
    }
}

inline static std::string to_string(const KeyState keyState) {
    switch (keyState) {
        case KeyState::Down:
            return "Down";
        case KeyState::Up:
            return "Up";
        case KeyState::Released:
            return "Released";
        case KeyState::Pressed:
            return "Pressed";
    }
}

inline static std::string to_string(const Point& point) {
    return "(" +
        std::to_string(point.x) +
        ", " +
        std::to_string(point.y) +
        ")";
}
}
