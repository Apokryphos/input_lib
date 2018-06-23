#pragma once

#include "input_lib/key_state.hpp"
#include <string>

namespace InputLib
{
inline static std::string to_string(const KeyState keyState) {
    switch (keyState) {
        case KeyState::Down:
            return "Down";
        case KeyState::Up:
            return "Up";
        case KeyState::Released:
            return "Released";
        case KeyState::Pressed:
            return "Pressed";
    }
}
}
