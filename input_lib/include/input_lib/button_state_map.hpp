#pragma once

#include "input_lib/button_state.hpp"
#include <iostream>
#include <map>

namespace InputLib
{
class ButtonStateMap
{
    std::map<unsigned, ButtonState> mMap;

public:
    void clear() {
        mMap.clear();
    }

    ButtonState getState(const unsigned button) const {
        return mMap.at(button);
    }

    ButtonState getState(const unsigned button, const ButtonState defaultButtonState) const {
        const auto& find = mMap.find(button);
        if (find == mMap.end()) {
            return defaultButtonState;
        }

        return find->second;
    }

    void setState(const unsigned button, ButtonState buttonState) {
        const ButtonState lastState = getState(button, ButtonState::Up);

        if (buttonState == ButtonState::Pressed) {
            if (lastState == ButtonState::Down ||
                lastState == ButtonState::Pressed) {
                buttonState = ButtonState::Down;
            }
        }

        mMap[button] = buttonState;
    }

    void update() {
        //  Update Pressed and Released states to Down and Up
        for (auto& p : mMap) {
            switch (p.second) {
                case ButtonState::Pressed:
                    p.second = ButtonState::Down;
                    break;

                case ButtonState::Released:
                    p.second = ButtonState::Up;
                    break;
            }
        }
    }
};
}
