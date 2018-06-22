#pragma once

#include "input_lib/action_type.hpp"
#include <string>

namespace InputLib
{
struct Action
{
    int id;
    ActionType type;

    bool operator<(const Action& other) const {
        return id < other.id;
    }
};
}
