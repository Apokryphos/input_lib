#pragma once

#include "input_lib/key.hpp"
#include "input_lib/key_state.hpp"
#include <iostream>
#include <map>

namespace InputLib
{
class KeyStateMap
{
    std::map<Key, KeyState> mMap;

public:
    void clear() {
        mMap.clear();
    }

    KeyState getState(const Key key) const {
        return mMap.at(key);
    }

    KeyState getState(const Key key, const KeyState defaultKeyState) const {
        const auto& find = mMap.find(key);
        if (find == mMap.end()) {
            return defaultKeyState;
        }

        return find->second;
    }

    void setState(const Key key, KeyState keyState) {
        const KeyState lastState = getState(key, KeyState::Up);

        if (keyState == KeyState::Pressed) {
            if (lastState == KeyState::Down ||
                lastState == KeyState::Pressed) {
                keyState = KeyState::Down;
            }
        }

        mMap[key] = keyState;
    }

    void update() {
        //  Update Pressed and Released states to Down and Up
        for (auto& p : mMap) {
            switch (p.second) {
                case KeyState::Pressed:
                    p.second = KeyState::Down;
                    break;

                case KeyState::Released:
                    p.second = KeyState::Up;
                    break;
            }
        }
    }
};
}
