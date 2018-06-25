#pragma once

#include "input_lib/axis.hpp"
#include "input_lib/button.hpp"
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
    std::map<ActionId, Axis> mAxisByActionId;
    std::map<ActionId, Button> mButtonsByActionId;
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
    void mapAction(const ActionId actionId, const Axis axis);
    void mapAction(const ActionId actionId, const Button button);
    void mapAction(const ActionId actionId, const Key key);
    void mapAction(
        const ActionId actionId,
        const Key negativeKey,
        const Key positiveKey
    );
};
}
