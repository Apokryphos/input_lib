#include "input_lib/gamepad_action_map.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
static float getAxisValue(const float value, const AxisRange axisRange) {
    switch (axisRange) {
        case AxisRange::Full:
            return value;
        case AxisRange::Positive:
            return value > 0.0f ? value : 0.0f;
        case AxisRange::Negative:
            return value < 0.0f ? value : 0.0f;
        default:
            throw std::runtime_error("Case not implemented.");
    }
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
                    entry.axisRange
                );

                if (value != 0.0f) {
                    return value;
                }
            }

            case InputType::Button: {
                const ButtonState buttonState =
                    gamepad.getButtonState(entry.value);
                const float value = buttonStateToAnalogValue(buttonState);
                if (value != 0.0f) {
                    return value;
                }
            }
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
                    entry.axisRange
                );

                if (value != 0.0f) {
                    return true;
                }
            }

            case InputType::Button: {
                const ButtonState buttonState =
                    gamepad.getButtonState(entry.value);
                const bool value = buttonStateToDigitalValue(buttonState);
                if (value) {
                    return true;
                }
            }
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

            case InputType::Button: {
                const ButtonState buttonState =
                    gamepad.getButtonState(entry.value);
                return buttonState == ButtonState::Pressed;
            }
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
void GamepadActionMap::map(
    const ActionId actionId,
    const GamepadAxis axis,
    const AxisRange axisRange
) {
    Entry entry = {};
    entry.inputType = InputType::Axis;
    entry.axisRange = axisRange;
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
