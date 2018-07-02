#pragma once

#include "input_lib/bimap.hpp"
#include "input_lib/button_state_map.hpp"
#include "input_lib/gamepad.hpp"
#include <map>
#include <string>

namespace InputLib
{
class GlfwGamepad : public Gamepad
{
    int mIndex;
    float mDeadzone;
    std::map<unsigned, float> mAxisMap;
    ButtonStateMap mButtonStateMap;
    std::string mName;

public:
    GlfwGamepad(int index);
    virtual ~GlfwGamepad() {}
    virtual float getAxisValue(const unsigned axis) const override;
    virtual ButtonState getButtonState(const unsigned button) const override;
    virtual const std::string& getName() const override;
    virtual bool isConnected() override;
    virtual bool isDown(const unsigned button) override;
    virtual bool isPressed(const unsigned button) override;
    void update();
};
}
