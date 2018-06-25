#pragma once

#include "input_lib/bimap.hpp"
#include "input_lib/button_state_map.hpp"
#include "input_lib/gamepad.hpp"
#include "input_lib/gamepad_input.hpp"
#include <map>

namespace InputLib
{
class GlfwGamepad : public Gamepad
{
    int mIndex;
    float mDeadzone;
    std::map<unsigned, float> mAxisMap;
    ButtonStateMap mButtonStateMap;

public:
    GlfwGamepad(int index);
    virtual ~GlfwGamepad() {}
    virtual float getAxisValue(const unsigned axis) const override;
    virtual ButtonState getButtonState(const Button button) const override;
    virtual bool isConnected() override;
    virtual bool isDown(const Button button) override;
    virtual bool isPressed(const Button button) override;
    void update();
};
}
