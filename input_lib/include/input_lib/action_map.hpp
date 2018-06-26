#pragma once

#include "input_lib/gamepad.hpp"
#include "input_lib/key.hpp"
#include "input_lib/keyboard.hpp"
#include <map>
#include <string>

namespace InputLib
{
typedef unsigned int ActionId;

class ActionMap
{
    std::map<ActionId, unsigned> mAxisByActionId;
    std::map<ActionId, unsigned> mButtonsByActionId;
    std::map<ActionId, Key> mKeysByActionId;
    std::map<ActionId, Key> mNegativeKeysByActionId;
    std::map<ActionId, Key> mPositiveKeysByActionId;

public:
    float getAnalogValue(const ActionId actionId, const Gamepad& gamepad) const;
    float getAnalogValue(const ActionId actionId, const Keyboard& keyboard) const;
    float getAxisValue(const ActionId actionId, const Gamepad& gamepad);
    float getAxisValue(const ActionId actionId, const Keyboard& keyboard);
    bool getDigitalValue(const ActionId actionId, const Gamepad& gamepad) const;
    bool getDigitalValue(const ActionId actionId, const Keyboard& keyboard) const;
    bool isPressed(const ActionId actionId, const Keyboard& keyboard) const;
    bool isPressed(const ActionId actionId, const Gamepad& gamepad) const;
    void mapAxis(const ActionId actionId, const unsigned axis);
    void mapButton(const ActionId actionId, const unsigned button);
    void mapKey(const ActionId actionId, const Key key);
    void mapKeys(
        const ActionId actionId,
        const Key negativeKey,
        const Key positiveKey
    );
};
}
