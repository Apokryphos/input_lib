#include "input_lib/keyboard_action_map.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
float KeyboardActionMap::getAnalogValue(
    const ActionId actionId,
    const Keyboard& keyboard
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return 0.0f;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        if (keyboard.isDown(entry.key)) {
            return 1.0f;
        }
    }

    return 0.0f;
}

//  ----------------------------------------------------------------------------
bool KeyboardActionMap::getDigitalValue(
    const ActionId actionId,
    const Keyboard& keyboard
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return false;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        if (keyboard.isDown(entry.key)) {
            return true;
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
bool KeyboardActionMap::isPressed(
    const ActionId actionId,
    const Keyboard& keyboard
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return false;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        if (keyboard.isPressed(entry.key)) {
            return true;
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
void KeyboardActionMap::map(const ActionId actionId, const Key key) {
    Entry entry = {};
    entry.key = key;

    mEntriesByActionId[actionId].push_back(entry);
}
}
