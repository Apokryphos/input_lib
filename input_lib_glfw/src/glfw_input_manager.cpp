#include "input_lib/bimap.hpp"
#include "input_lib/glfw/glfw_input_manager.hpp"
#include "input_lib/glfw/glfw_key_map.hpp"
#include <GLFW/glfw3.h>
#include <algorithm>
#include <cassert>
#include <vector>

namespace InputLib
{
static GlfwInputManager* sInputManager;
static Bimap<Key, int> sKeyMap;

//  ----------------------------------------------------------------------------
static void updateKeyState(int glfwKey, const KeyState keyState) {
    auto& keyboard = sInputManager->getKeyboard();
    auto& keyStateMap = static_cast<GlfwKeyboard&>(keyboard).getKeyStateMap();
    const Key key = sKeyMap.getKey(glfwKey, Key::None);
    keyStateMap.setState(key, keyState);
}

//  ----------------------------------------------------------------------------
void keyboardCallback(
    GLFWwindow* window,
    int key,
    [[maybe_unused]] int scancode,
    int action,
    [[maybe_unused]] int mods) {
    if (sInputManager == nullptr) {
        return;
    }

    switch (action) {
        case GLFW_PRESS:
            updateKeyState(key, KeyState::Pressed);
            break;

        case GLFW_REPEAT:
            updateKeyState(key, KeyState::Down);
            break;

        case GLFW_RELEASE:
            updateKeyState(key, KeyState::Released);
            break;
    }
}

//  ----------------------------------------------------------------------------
GlfwInputManager::GlfwInputManager() {
    assert(sInputManager == nullptr);
    sInputManager = this;
    initializeGlfwKeyMap(sKeyMap);
}

//  ----------------------------------------------------------------------------
GlfwInputManager::~GlfwInputManager() {
    sInputManager = nullptr;
}

//  ----------------------------------------------------------------------------
Mouse& GlfwInputManager::getMouse() {
    // return mMouse;
}

//  ----------------------------------------------------------------------------
Keyboard& GlfwInputManager::getKeyboard() {
    return mKeyboard;
}

//  ----------------------------------------------------------------------------
void GlfwInputManager::update() {
    //  Update Pressed and Released states to Down and Up
    auto& keyStateMap = mKeyboard.getKeyStateMap();
    keyStateMap.update();

    glfwPollEvents();
}
}
