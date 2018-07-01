#pragma once

#include "input_lib/gamepad_axis.hpp"
#include "input_lib/gamepad_button.hpp"

namespace InputLib
{
class Gamepad360
{
public:
    //  Axes
    static const GamepadAxis LEFT_STICK_X = GamepadAxis::Axis1;
    static const GamepadAxis LEFT_STICK_Y = GamepadAxis::Axis2;
    static const GamepadAxis LEFT_TRIGGER = GamepadAxis::Axis3;
    static const GamepadAxis RIGHT_STICK_X = GamepadAxis::Axis4;
    static const GamepadAxis RIGHT_STICK_Y = GamepadAxis::Axis5;
    static const GamepadAxis RIGHT_TRIGGER = GamepadAxis::Axis6;

    //  Buttons
    static const GamepadButton A_BUTTON = GamepadButton::Button1;
    static const GamepadButton B_BUTTON = GamepadButton::Button2;
    static const GamepadButton X_BUTTON = GamepadButton::Button3;
    static const GamepadButton Y_BUTTON = GamepadButton::Button4;
    static const GamepadButton LEFT_BUMPER = GamepadButton::Button5;
    static const GamepadButton RIGHT_BUMPER = GamepadButton::Button6;
    static const GamepadButton BACK_BUTTON = GamepadButton::Button7;
    static const GamepadButton START_BUTTON = GamepadButton::Button8;
    static const GamepadButton GUIDE_BUTTON = GamepadButton::Button9;
    static const GamepadButton LEFT_THUMB = GamepadButton::Button10;
    static const GamepadButton RIGHT_THUMB = GamepadButton::Button11;
    static const GamepadButton DPAD_UP = GamepadButton::Button12;
    static const GamepadButton DPAD_RIGHT = GamepadButton::Button13;
    static const GamepadButton DPAD_DOWN = GamepadButton::Button14;
    static const GamepadButton DPAD_LEFT = GamepadButton::Button15;
};
}
