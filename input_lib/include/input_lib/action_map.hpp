#pragma once

#include "input_lib/action_id.hpp"
#include "input_lib/device.hpp"
#include "input_lib/gamepad_action_map.hpp"
#include "input_lib/keyboard_action_map.hpp"
#include "input_lib/mouse_action_map.hpp"

namespace InputLib
{
class ActionMap
{
    KeyboardActionMap mKeyboardActionMap;
    MouseActionMap mMouseActionMap;
    GamepadActionMap mGamepadActionMap;

public:
    float getAnalogValue(
        const ActionId actionId,
        const Device& device
    ) const;
    bool getDigitalValue(
        const ActionId actionId,
        const Device& device
    ) const;
    bool isPressed(
        const ActionId actionId,
        const Device& device
    ) const;
    void map(const ActionId actionId, const GamepadAxis axis);
    void map(const ActionId actionId, const GamepadButton button);
    void map(const ActionId actionId, const Key key);
    void map(const ActionId actionId, const MouseButton button);
};
}
