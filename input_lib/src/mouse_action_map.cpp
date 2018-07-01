#include "input_lib/mouse_action_map.hpp"

namespace InputLib
{
//  ----------------------------------------------------------------------------
float MouseActionMap::getAnalogValue(
    const ActionId actionId,
    const Mouse& mouse
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return 0.0f;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        if (mouse.isDown(entry.buttonIndex)) {
            return 1.0f;
        }
    }

    return 0.0f;
}

//  ----------------------------------------------------------------------------
bool MouseActionMap::getDigitalValue(
    const ActionId actionId,
    const Mouse& mouse
) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return false;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        if (mouse.isDown(entry.buttonIndex)) {
            return true;
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
bool MouseActionMap::isPressed(const ActionId actionId, const Mouse& mouse) const {
    const auto& find = mEntriesByActionId.find(actionId);

    if (find == mEntriesByActionId.end()) {
        return false;
    }

    const auto& entries = find->second;

    for (const auto& entry : entries) {
        if (mouse.isPressed(entry.buttonIndex)) {
            return true;
        }
    }

    return false;
}

//  ----------------------------------------------------------------------------
void MouseActionMap::map(const ActionId actionId, const MouseButton button) {
    Entry entry = {};
    entry.buttonIndex = static_cast<unsigned>(button);

    mEntriesByActionId[actionId].push_back(entry);
}
}
