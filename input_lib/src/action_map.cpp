#include "input_lib/action_map.hpp"
#include "input_lib/button_state.hpp"
#include "input_lib/key_state.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
float ActionMap::getAnalogValue(
    const ActionId actionId,
    const Gamepad& gamepad
) const {
    const unsigned button = mButtonsByActionId.at(actionId);
    const ButtonState buttonState = gamepad.getButtonState(button);
    return buttonStateToAnalogValue(buttonState);
}

//  ----------------------------------------------------------------------------
float ActionMap::getAnalogValue(
    const ActionId actionId,
    const Keyboard& keyboard
) const {
    const Key key = mKeysByActionId.at(actionId);
    const KeyState keyState = keyboard.getKeyState(key);
    return keyStateToAnalogValue(keyState);
}

//  ----------------------------------------------------------------------------
float ActionMap::getAxisValue(const ActionId actionId, const Gamepad& gamepad) {
    const unsigned axis = mAxisByActionId.at(actionId);
    return gamepad.getAxisValue(axis);
}

//  ----------------------------------------------------------------------------
float ActionMap::getAxisValue(const ActionId actionId, const Keyboard& keyboard) {
    const Key negativeKey = mNegativeKeysByActionId.at(actionId);
    const Key positiveKey = mPositiveKeysByActionId.at(actionId);

    const KeyState negativeKeyState = keyboard.getKeyState(negativeKey);
    const KeyState positiveKeyState = keyboard.getKeyState(positiveKey);

    const bool nDown = (
        negativeKeyState == KeyState::Down ||
        negativeKeyState == KeyState::Pressed
    );

    const bool pDown = (
        positiveKeyState == KeyState::Down ||
        positiveKeyState == KeyState::Pressed
    );

    if (nDown && pDown) {
        return 0.0f;
    }

    if (nDown) {
        return -1.0f;
    }

    if (pDown) {
        return 1.0f;
    }

    return 0.0f;
}

//  ----------------------------------------------------------------------------
bool ActionMap::getDigitalValue(
    const ActionId actionId,
    const Gamepad& gamepad
) const {
    const unsigned button = mButtonsByActionId.at(actionId);
    const ButtonState buttonState = gamepad.getButtonState(button);
    return buttonStateToDigitalValue(buttonState);
}

//  ----------------------------------------------------------------------------
bool ActionMap::getDigitalValue(
    const ActionId actionId,
    const Keyboard& keyboard
) const {
    const Key key = mKeysByActionId.at(actionId);
    const KeyState keyState = keyboard.getKeyState(key);
    return keyStateToDigitalValue(keyState);
}

//  ----------------------------------------------------------------------------
bool ActionMap::isPressed(
    const ActionId actionId,
    const Keyboard& keyboard
) const {
    const Key key = mKeysByActionId.at(actionId);
    const KeyState keyState = keyboard.getKeyState(key);
    return keyState == KeyState::Pressed;
}

//  ----------------------------------------------------------------------------
bool ActionMap::isPressed(
    const ActionId actionId,
    const Gamepad& gamepad
) const {
    const unsigned button = mButtonsByActionId.at(actionId);
    const ButtonState buttonState = gamepad.getButtonState(button);
    return buttonState == ButtonState::Pressed;
}

//  ----------------------------------------------------------------------------
void ActionMap::mapAxis(const ActionId actionId, const unsigned axis) {
    mAxisByActionId.emplace(actionId, axis);
}

//  ----------------------------------------------------------------------------
void ActionMap::mapButton(const ActionId actionId, const unsigned button) {
    mButtonsByActionId.emplace(actionId, button);
}

//  ----------------------------------------------------------------------------
void ActionMap::mapKey(const ActionId actionId, const Key key) {
    mKeysByActionId.emplace(actionId, key);
}

//  ----------------------------------------------------------------------------
void ActionMap::mapKeys(
    const ActionId actionId,
    const Key negativeKey,
    const Key positiveKey
) {
    mNegativeKeysByActionId.emplace(actionId, negativeKey);
    mPositiveKeysByActionId.emplace(actionId, positiveKey);
}
}
