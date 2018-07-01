#pragma once

#include "input_lib/action_id.hpp"
#include "input_lib/gamepad.hpp"
#include "input_lib/gamepad_axis.hpp"
#include "input_lib/gamepad_button.hpp"
#include "input_lib/input_type.hpp"
#include <map>
#include <vector>

namespace InputLib
{
class GamepadActionMap
{
    struct Entry
    {
        InputType inputType;
        unsigned value;
    };

    std::map<ActionId, std::vector<Entry>> mEntriesByActionId;

public:
    float getAnalogValue(
        const ActionId actionId,
        const Gamepad& gamepad
    ) const;
    bool getDigitalValue(
        const ActionId actionId,
        const Gamepad& gamepad
    ) const;
    bool isPressed(const ActionId actionId, const Gamepad& gamepad) const;
    void map(const ActionId actionId, const GamepadAxis axis);
    void map(const ActionId actionId, const GamepadButton button);
};
}
