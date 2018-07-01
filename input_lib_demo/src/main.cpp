#include <glad/glad.h>
#include "input_lib/action_map.hpp"
#include "input_lib/gamepad_360.hpp"
#include "input_lib/to_string.hpp"
#include "input_lib/glfw/glfw_input_manager.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace InputLib;

enum InputActionId
{
    Accept,
    Accelerate,
    Crouch,
    MenuUp,
    MoveLeft,
    MoveRight,
    Quit,
};

//  ----------------------------------------------------------------------------
static void error_callback(int error, const char* description)
{
    std::cerr << "OpenGL Error: " << description << std::endl;
}

//  ----------------------------------------------------------------------------
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(320, 240, "InputLib Demo", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, InputLib::keyboardCallback);
    glfwSetJoystickCallback(InputLib::joystickCallback);
    glfwSetCursorPosCallback(window, mousePositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cerr << "Glad failed to initialize." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        throw std::runtime_error("GLAD failed to initialize.");
    }

    GlfwInputManager inputManager;

    auto& keyboard = inputManager.getKeyboard();
    auto& mouse = inputManager.getMouse();
    auto& gamepad = inputManager.getGamepad(0);

    std::vector<Device*> devices = {
        &keyboard,
        &mouse,
        &gamepad,
    };

    ActionMap actionMap;

    //  Keyboard mapping
    actionMap.map(InputActionId::Accept, Key::Enter);
    actionMap.map(InputActionId::Accelerate, Key::Space);
    actionMap.map(InputActionId::MenuUp, Key::Up);
    actionMap.map(InputActionId::MoveLeft, Key::A);
    actionMap.map(InputActionId::MoveRight, Key::E);
    actionMap.map(InputActionId::Quit, Key::Escape);

    // actionMap.mapKeys(
    //     InputActionId::MoveX,
    //     Key::Left,
    //     Key::Right
    // );

    //  Mouse mapping
    actionMap.map(InputActionId::Accept, MouseButton::LeftButton);
    actionMap.map(InputActionId::Crouch, MouseButton::RightButton);

    //  Gamepad mapping
    actionMap.map(InputActionId::Accept, Gamepad360::A_BUTTON);
    actionMap.map(InputActionId::Accelerate, Gamepad360::RIGHT_TRIGGER);
    actionMap.map(InputActionId::Crouch, Gamepad360::B_BUTTON);
    actionMap.map(
        InputActionId::MoveLeft,
        Gamepad360::LEFT_STICK_X,
        AxisRange::Negative
    );
    actionMap.map(
        InputActionId::MoveRight,
        Gamepad360::LEFT_STICK_X,
        AxisRange::Positive
    );
    actionMap.map(InputActionId::Quit, Gamepad360::BACK_BUTTON);

    Point lastMousePosition;

    while (!glfwWindowShouldClose(window)) {
        inputManager.update();

        const Point mousePosition = mouse.getPosition();
        if (mousePosition != lastMousePosition) {
            std::cout << "MOUSE " << to_string(mousePosition) << std::endl;
            lastMousePosition = mousePosition;
        }

        if (mouse.isPressed(0)) {
            std::cout << "MOUSE LEFT BUTTON" << std::endl;
        }

        for (const auto& d : devices) {
            const Device& device = *d;

            if (actionMap.getDigitalValue(InputActionId::Quit, device)) {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }

            if (actionMap.isPressed(InputActionId::Accept, device)) {
                std::cout << "ACCEPT" << std::endl;
            }

            if (actionMap.getDigitalValue(InputActionId::Crouch, device)) {
                std::cout << "CROUCH" << std::endl;
            }

            if (actionMap.isPressed(InputActionId::MenuUp, device)) {
                std::cout << "MENU UP" << std::endl;
            }

            // if (actionMap.getDigitalValue(InputActionId::Accelerate, device)) {
            //     std::cout <<
            //         "ACCELERATE X " <<
            //         actionMap.getAnalogValue(InputActionId::Accelerate, device) <<
            //         std::endl;
            // }

            if (actionMap.getDigitalValue(InputActionId::MoveLeft, device)) {
                std::cout <<
                    "MOVE LEFT " <<
                    actionMap.getAnalogValue(InputActionId::MoveLeft, device) <<
                    std::endl;
            }

            if (actionMap.getDigitalValue(InputActionId::MoveRight, device)) {
                std::cout <<
                    "MOVE RIGHT " <<
                    actionMap.getAnalogValue(InputActionId::MoveRight, device) <<
                    std::endl;
            }
        }

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
