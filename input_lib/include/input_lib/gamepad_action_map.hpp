#pragma once

#include "input_lib/action_id.hpp"
#include "input_lib/axis_range.hpp"
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
        AxisRange axisRange;
        unsigned value;
        float minAnalogValue;
        float maxAnalogValue;
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
    void map(
        const ActionId actionId,
        const GamepadAxis axis,
        const AxisRange axisRange = AxisRange::Full,
        const float minAnalogValue = -1.0f,
        const float maxAnalogValue = 1.0f
    );
    void map(const ActionId actionId, const GamepadButton button);
};
}
