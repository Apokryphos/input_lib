#pragma once

#include "input_lib/action_id.hpp"
#include "input_lib/mouse.hpp"
#include "input_lib/mouse_button.hpp"
#include <map>
#include <vector>

namespace InputLib
{
class MouseActionMap
{
    struct Entry
    {
        unsigned buttonIndex;
    };

    std::map<ActionId, std::vector<Entry>> mEntriesByActionId;

public:
    float getAnalogValue(
        const ActionId actionId,
        const Mouse& mouse
    ) const;
    bool getDigitalValue(
        const ActionId actionId,
        const Mouse& mouse
    ) const;
    bool isPressed(const ActionId actionId, const Mouse& mouse) const;
    void map(const ActionId actionId, const MouseButton button);
};
}
