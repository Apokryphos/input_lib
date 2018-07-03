#pragma once

#include "input_lib/action_id.hpp"
#include "input_lib/key.hpp"
#include "input_lib/keyboard.hpp"
#include <map>
#include <vector>

namespace InputLib
{
class KeyboardActionMap
{
    struct Entry
    {
        Key key;
        //  Analog value used when key is down
        float analogValue;
    };

    std::map<ActionId, std::vector<Entry>> mEntriesByActionId;

public:
    float getAnalogValue(
        const ActionId actionId,
        const Keyboard& keyboard
    ) const;
    bool getDigitalValue(
        const ActionId actionId,
        const Keyboard& keyboard
    ) const;
    bool isPressed(
        const ActionId actionId,
        const Keyboard& keyboard
    ) const;
    void map(
        const ActionId actionId,
        const Key key,
        const float analogValue = 1.0f
    );
};
}
