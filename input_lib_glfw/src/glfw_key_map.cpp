#include "input_lib/bimap.hpp"
#include "input_lib/key.hpp"
#include <GLFW/glfw3.h>

namespace InputLib
{
//  ----------------------------------------------------------------------------
void initializeGlfwKeyMap(Bimap<Key, int>& keyMap) {
    keyMap.clear();

    keyMap.map(Key::Enter, GLFW_KEY_ENTER);
    keyMap.map(Key::Escape, GLFW_KEY_ESCAPE);
    keyMap.map(Key::Space, GLFW_KEY_SPACE);
    keyMap.map(Key::Up, GLFW_KEY_UP);
    //  Digits
    keyMap.map(Key::D0, GLFW_KEY_0);
    keyMap.map(Key::D1, GLFW_KEY_1);
    keyMap.map(Key::D2, GLFW_KEY_2);
    keyMap.map(Key::D3, GLFW_KEY_3);
    keyMap.map(Key::D4, GLFW_KEY_4);
    keyMap.map(Key::D5, GLFW_KEY_5);
    keyMap.map(Key::D6, GLFW_KEY_6);
    keyMap.map(Key::D7, GLFW_KEY_7);
    keyMap.map(Key::D8, GLFW_KEY_8);
    keyMap.map(Key::D9, GLFW_KEY_9);
    //  Letters
}
}
