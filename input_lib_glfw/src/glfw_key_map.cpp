#include "input_lib/bimap.hpp"
#include "input_lib/key.hpp"
#include <GLFW/glfw3.h>

namespace InputLib
{
//  ----------------------------------------------------------------------------
void initializeGlfwKeyMap(Bimap<Key, int>& keyMap) {
    keyMap.clear();

    keyMap.map(Key::Comma, GLFW_KEY_COMMA);
    keyMap.map(Key::Down, GLFW_KEY_DOWN);
    keyMap.map(Key::Enter, GLFW_KEY_ENTER);
    keyMap.map(Key::Equal, GLFW_KEY_EQUAL);
    keyMap.map(Key::Escape, GLFW_KEY_ESCAPE);
    keyMap.map(Key::Left, GLFW_KEY_LEFT);
    keyMap.map(Key::LeftBracket, GLFW_KEY_LEFT_BRACKET);
    keyMap.map(Key::LeftShift, GLFW_KEY_LEFT_SHIFT);
    keyMap.map(Key::Minus, GLFW_KEY_MINUS);
    keyMap.map(Key::Right, GLFW_KEY_RIGHT);
    keyMap.map(Key::RightBracket, GLFW_KEY_RIGHT_BRACKET);
    keyMap.map(Key::Semicolon, GLFW_KEY_SEMICOLON);
    keyMap.map(Key::Space, GLFW_KEY_SPACE);
    keyMap.map(Key::Tab, GLFW_KEY_TAB);
    keyMap.map(Key::Up, GLFW_KEY_UP);
    //  Function
    keyMap.map(Key::F1, GLFW_KEY_F1);
    keyMap.map(Key::F2, GLFW_KEY_F2);
    keyMap.map(Key::F3, GLFW_KEY_F3);
    keyMap.map(Key::F4, GLFW_KEY_F4);
    keyMap.map(Key::F5, GLFW_KEY_F5);
    keyMap.map(Key::F6, GLFW_KEY_F6);
    keyMap.map(Key::F7, GLFW_KEY_F7);
    keyMap.map(Key::F8, GLFW_KEY_F8);
    keyMap.map(Key::F9, GLFW_KEY_F9);
    keyMap.map(Key::F10, GLFW_KEY_F10);
    keyMap.map(Key::F11, GLFW_KEY_F11);
    keyMap.map(Key::F12, GLFW_KEY_F12);
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
    keyMap.map(Key::A, GLFW_KEY_A);
    keyMap.map(Key::B, GLFW_KEY_B);
    keyMap.map(Key::C, GLFW_KEY_C);
    keyMap.map(Key::D, GLFW_KEY_D);
    keyMap.map(Key::E, GLFW_KEY_E);
    keyMap.map(Key::F, GLFW_KEY_F);
    keyMap.map(Key::G, GLFW_KEY_G);
    keyMap.map(Key::H, GLFW_KEY_H);
    keyMap.map(Key::I, GLFW_KEY_I);
    keyMap.map(Key::J, GLFW_KEY_J);
    keyMap.map(Key::K, GLFW_KEY_K);
    keyMap.map(Key::L, GLFW_KEY_L);
    keyMap.map(Key::M, GLFW_KEY_M);
    keyMap.map(Key::N, GLFW_KEY_N);
    keyMap.map(Key::O, GLFW_KEY_O);
    keyMap.map(Key::P, GLFW_KEY_P);
    keyMap.map(Key::Q, GLFW_KEY_Q);
    keyMap.map(Key::R, GLFW_KEY_R);
    keyMap.map(Key::S, GLFW_KEY_S);
    keyMap.map(Key::T, GLFW_KEY_T);
    keyMap.map(Key::U, GLFW_KEY_U);
    keyMap.map(Key::V, GLFW_KEY_V);
    keyMap.map(Key::W, GLFW_KEY_W);
    keyMap.map(Key::X, GLFW_KEY_X);
    keyMap.map(Key::Y, GLFW_KEY_Y);
    keyMap.map(Key::Z, GLFW_KEY_Z);
}
}
