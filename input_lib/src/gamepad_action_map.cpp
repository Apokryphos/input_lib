#include "input_lib/gamepad_action_map.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
static float getAxisValue(
    const float value,
    const AxisRange axisRange,
    const float minAnalogValue,
    const float maxAnalogValue
) {
    float v;

    switch (axisRange) {
        case AxisRange::Full:
            v = value;
            break;
        case AxisRange::Positive:
            v = value > 0.0f ? value : 0.0f;
            break;
        case AxisRange::Negative:
            v = value < 0.0f ? value : 0.0f;
            break;
        default:
            throw std::runtime_error("Case not implemented.");
    }

    const float inStart = -1.0f;
    const float inEnd = 1.0f;

    return
        (v - inStart) / (inEnd - inStart)
        * (maxAnalogValue - minAnalogValue)
        + minAnalogValue;
}

//  ----------------------------------------------------------------------------
float GamepadActionMap::getAnalogValue(
    const ActionId actionId,
    const Gamepad& gamepad
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return 0.0f;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        switch (entry.inputType) {
            case InputType::Axis: {
                const float value = getAxisValue(
                    gamepad.getAxisValue(entry.value),
                    entry.axisRange,
                    entry.minAnalogValue,
                    entry.maxAnalogValue
                );

                if (value != 0.0f) {
                    return value;
                }
            }
            break;

            case InputType::Button: {
                const ButtonState buttonState =
                    gamepad.getButtonState(entry.value);
                const float value = buttonStateToAnalogValue(buttonState);
                if (value != 0.0f) {
                    return value;
                }
            }
            break;
        }
    }

    return 0.0f;
}

//  ----------------------------------------------------------------------------
bool GamepadActionMap::getDigitalValue(
    const ActionId actionId,
    const Gamepad& gamepad
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return 0.0f;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        switch (entry.inputType) {
            case InputType::Axis: {
                const float value = getAxisValue(
                    gamepad.getAxisValue(entry.value),
                    entry.axisRange,
                    entry.minAnalogValue,
                    entry.maxAnalogValue
                );

                if (value != 0.0f) {
                    return true;
                }
            }
            break;

            case InputType::Button: {
                const ButtonState buttonState =
                    gamepad.getButtonState(entry.value);
                const bool value = buttonStateToDigitalValue(buttonState);
                if (value) {
                    return true;
                }
            }
            break;
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
bool GamepadActionMap::isPressed(
    const ActionId actionId,
    const Gamepad& gamepad
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return 0.0f;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        switch (entry.inputType) {
            case InputType::Axis: {
                throw std::runtime_error("Not implemented.");
            }
            break;

            case InputType::Button: {
                const ButtonState buttonState =
                    gamepad.getButtonState(entry.value);
                return buttonState == ButtonState::Pressed;
            }
            break;
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
void GamepadActionMap::map(
    const ActionId actionId,
    const GamepadAxis axis,
    const AxisRange axisRange,
    const float minAnalogValue,
    const float maxAnalogValue
) {
    Entry entry = {};
    entry.inputType = InputType::Axis;
    entry.axisRange = axisRange;
    entry.minAnalogValue = std::min(minAnalogValue, maxAnalogValue);;
    entry.maxAnalogValue = std::max(minAnalogValue, maxAnalogValue);
    entry.value = static_cast<unsigned>(axis);

    mEntriesByActionId[actionId].push_back(entry);
}

//  ----------------------------------------------------------------------------
void GamepadActionMap::map(
    const ActionId actionId,
    const GamepadButton button
) {
    Entry entry = {};
    entry.inputType = InputType::Button;
    entry.value = static_cast<unsigned>(button);

    mEntriesByActionId[actionId].push_back(entry);
}
}
