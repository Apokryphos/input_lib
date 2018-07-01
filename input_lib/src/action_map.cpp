#include "input_lib/action_map.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
float ActionMap::getAnalogValue(
    const ActionId actionId,
    const Device& device
) const {
    switch (device.getDeviceType()) {
        case DeviceType::Gamepad:
            return mGamepadActionMap.getAnalogValue(
                actionId,
                static_cast<const Gamepad&>(device)
            );
        case DeviceType::Keyboard:
            return mKeyboardActionMap.getAnalogValue(
                actionId,
                static_cast<const Keyboard&>(device)
            );
        case DeviceType::Mouse:
            return mMouseActionMap.getAnalogValue(
                actionId,
                static_cast<const Mouse&>(device)
            );
    }

    return 0.0f;
}

//  ----------------------------------------------------------------------------
bool ActionMap::getDigitalValue(
    const ActionId actionId,
    const Device& device
) const {
    switch (device.getDeviceType()) {
        case DeviceType::Gamepad:
            return mGamepadActionMap.getDigitalValue(
                actionId,
                static_cast<const Gamepad&>(device)
            );
        case DeviceType::Keyboard:
            return mKeyboardActionMap.getDigitalValue(
                actionId,
                static_cast<const Keyboard&>(device)
            );
        case DeviceType::Mouse:
            return mMouseActionMap.getDigitalValue(
                actionId,
                static_cast<const Mouse&>(device)
            );
    }

    return false;
}

//  ----------------------------------------------------------------------------
bool ActionMap::isPressed(
    const ActionId actionId,
    const Device& device
) const {
    switch (device.getDeviceType()) {
        case DeviceType::Gamepad:
            return mGamepadActionMap.isPressed(
                actionId,
                static_cast<const Gamepad&>(device)
            );
        case DeviceType::Keyboard:
            return mKeyboardActionMap.isPressed(
                actionId,
                static_cast<const Keyboard&>(device)
            );
        case DeviceType::Mouse:
            return mMouseActionMap.isPressed(
                actionId,
                static_cast<const Mouse&>(device)
            );
    }

    return false;
}

//  ----------------------------------------------------------------------------
void ActionMap::map(
    const ActionId actionId,
    const GamepadAxis axis
) {
    mGamepadActionMap.map(actionId, axis);
}

//  ----------------------------------------------------------------------------
void ActionMap:: map(
    const ActionId actionId,
    const GamepadButton button
) {
    mGamepadActionMap.map(actionId, button);
}

//  ----------------------------------------------------------------------------
void ActionMap::map(
    const ActionId actionId,
    const Key key
) {
    mKeyboardActionMap.map(actionId, key);
}

//  ----------------------------------------------------------------------------
void ActionMap::map(
    const ActionId actionId,
    const MouseButton button
) {
    mMouseActionMap.map(actionId, button);
}
}
