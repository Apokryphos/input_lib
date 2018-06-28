#include <glad/glad.h>
#include "input_lib/action_map.hpp"
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
    MoveX,
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

    ActionMap actionMap;
    actionMap.mapKey(InputActionId::Accept, Key::Enter);
    actionMap.mapKey(InputActionId::Accelerate, Key::Space);
    actionMap.mapKey(InputActionId::MenuUp, Key::Up);
    actionMap.mapKey(InputActionId::Quit, Key::Escape);

    actionMap.mapKeys(
        InputActionId::MoveX,
        Key::Left,
        Key::Right
    );

    actionMap.mapButton(InputActionId::Accept, 0);
    actionMap.mapAxis(InputActionId::Accelerate, 2);
    actionMap.mapButton(InputActionId::Crouch, 1);
    actionMap.mapAxis(InputActionId::MoveX, 0);

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

        if (actionMap.getDigitalValue(InputActionId::Quit, keyboard)) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        if (actionMap.isPressed(InputActionId::Accept, keyboard)) {
            std::cout << "ACCEPT" << std::endl;
        }

        if (actionMap.getDigitalValue(InputActionId::MenuUp, keyboard)) {
            std::cout << "MOVE UP" << std::endl;
        }

        if (actionMap.getAxisValue(InputActionId::MoveX, keyboard) != 0.0f) {
            std::cout <<
                "MOVE X " <<
                actionMap.getAxisValue(InputActionId::MoveX, keyboard) <<
                std::endl;
        }

        if (actionMap.isPressed(InputActionId::Accept, gamepad)) {
            std::cout << "ACCEPT" << std::endl;
        }

        if (actionMap.getDigitalValue(InputActionId::Crouch, gamepad)) {
            std::cout << "CROUCH" << std::endl;
        }

        // if (actionMap.getAxisValue(InputActionId::Accelerate, gamepad) != 0.0f) {
        //     std::cout <<
        //         "ACCELERATE X " <<
        //         actionMap.getAxisValue(InputActionId::Accelerate, gamepad) <<
        //         std::endl;
        // }

        if (actionMap.getAxisValue(InputActionId::MoveX, gamepad) != 0.0f) {
            std::cout <<
                "MOVE X " <<
                actionMap.getAxisValue(InputActionId::MoveX, gamepad) <<
                std::endl;
        }

        float ratio;
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
