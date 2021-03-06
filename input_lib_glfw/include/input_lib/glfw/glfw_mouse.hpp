#pragma once

#include "input_lib/mouse.hpp"
#include "input_lib/button_state_map.hpp"

namespace InputLib
{
class GlfwMouse : public Mouse
{
    float mScroll;
    Coord mPosition;
    ButtonStateMap mButtonStateMap;

public:
    virtual ButtonState getButtonState(const unsigned button) const override;
    ButtonStateMap& getButtonStateMap();
    virtual ButtonState getLeftButtonState() const override;
    virtual ButtonState getMiddleButtonState() const override;
    virtual const std::string& getName() const override;
    virtual Coord getPosition() override;
    virtual ButtonState getRightButtonState() const override;
    virtual float getScroll() const override;
    virtual bool isDown(const unsigned button) const override;
    virtual bool isPressed(const unsigned button) const override;
    void setPosition(float x, float y);
    void setScroll(float scroll);
    void update();
};
}
