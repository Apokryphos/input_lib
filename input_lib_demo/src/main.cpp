#include <glad/glad.h>
#include "input_lib/action_map.hpp"
#include "input_lib/deadzone.hpp"
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
    MenuDown,
    MenuUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    MoveUp,
    Quit,
};

//  ----------------------------------------------------------------------------
static void error_callback(int error, const char* description) {
    std::cerr << "OpenGL Error: " << description << std::endl;
}

//  ----------------------------------------------------------------------------
static std::string to_string(const InputActionId actionId) {
    switch (actionId) {
        case InputActionId::Accept:
            return "Accept";
        case InputActionId::Accelerate:
            return "Accelerate";
        case InputActionId::Crouch:
            return "Crouch";
        case InputActionId::MenuDown:
            return "Menu Down";
        case InputActionId::MenuUp:
            return "Menu Up";
        case InputActionId::MoveDown:
            return "Move Down";
        case InputActionId::MoveLeft:
            return "Move Left";
        case InputActionId::MoveRight:
            return "Move Right";
        case InputActionId::MoveUp:
            return "Move Up";
        case InputActionId::Quit:
            return "Quit";
        default:
            return "?";
    }
}

//  ----------------------------------------------------------------------------
static void printAnalogAction(
    const InputActionId actionId,
    const ActionMap& actionMap,
    const Device& device,
    const float deadzoneAmount = 0.2f,
    DeadzoneFloatFilter deadzoneFilter = basicDeadzone
) {
    if (actionMap.getDigitalValue(actionId, device)) {
        const float value = deadzoneFilter(
            deadzoneAmount,
            actionMap.getAnalogValue(actionId, device)
        );

        if (value == 0.0f) {
            return;
        }

        std::cout <<
            device.getName() << ": " <<
            to_string(actionId) << " (" <<
            value <<
            ")" <<
            std::endl;
    }
}

//  ----------------------------------------------------------------------------
static void printAnalogAction(
    const std::string& label,
    const InputActionId xPosActionId,
    const InputActionId xNegActionId,
    const InputActionId yPosActionId,
    const InputActionId yNegActionId,
    const ActionMap& actionMap,
    const Device& device,
    const float deadzoneAmount = 0.2f,
    DeadzonePointFilter deadzoneFilter = radialDeadzone
) {
    const float xp = actionMap.getAnalogValue(xPosActionId, device);
    const float xn = actionMap.getAnalogValue(xNegActionId, device);
    const float yp = actionMap.getAnalogValue(yPosActionId, device);
    const float yn = actionMap.getAnalogValue(yNegActionId, device);

    const float x = xp > 0.0f ? xp : xn < 0.0f ? xn : 0.0f;
    const float y = yp > 0.0f ? yp : yn < 0.0f ? yn : 0.0f;

    Point p = deadzoneFilter(deadzoneAmount, x, y);

    if (p.x == 0.0f && p.y == 0.0f) {
        return;
    }

    std::cout <<
        device.getName() << ": " <<
        label << " " <<
        to_string(p) <<
        std::endl;
}

//  ----------------------------------------------------------------------------
static void printDigitalAction(
    const InputActionId actionId,
    const ActionMap& actionMap,
    const Device& device
) {
    if (actionMap.getDigitalValue(actionId, device)) {
        std::cout <<
            device.getName() << ": " <<
            to_string(actionId) <<
            std::endl;
    }
}

//  ----------------------------------------------------------------------------
static void printPressedAction(
    const InputActionId actionId,
    const ActionMap& actionMap,
    const Device& device
) {
    if (actionMap.isPressed(actionId, device)) {
        std::cout <<
            device.getName() << ": " <<
            to_string(actionId) <<
            std::endl;
    }
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
    window = glfwCreateWindow(640, 480, "InputLib Demo", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //  Set input callbacks
    glfwSetKeyCallback(window, keyboardCallback);
    glfwSetJoystickCallback(joystickCallback);
    glfwSetCursorPosCallback(window, mousePositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, scrollCallback);

    glfwMakeContextCurrent(window);

    //  glad
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
    actionMap.map(InputActionId::MenuDown, Key::Down);
    actionMap.map(InputActionId::MenuUp, Key::Up);
    actionMap.map(InputActionId::MoveLeft, Key::A);
    actionMap.map(InputActionId::MoveRight, Key::E);
    actionMap.map(InputActionId::MoveUp, Key::Comma);
    actionMap.map(InputActionId::MoveDown, Key::O);
    actionMap.map(InputActionId::Quit, Key::Escape);

    //  Mouse mapping
    actionMap.map(InputActionId::Accept, MouseButton::LeftButton);
    actionMap.map(InputActionId::Crouch, MouseButton::RightButton);

    //  Gamepad mapping
    actionMap.map(InputActionId::Accept, Gamepad360::A_BUTTON);
    actionMap.map(InputActionId::Accelerate, Gamepad360::RIGHT_TRIGGER);
    actionMap.map(InputActionId::Crouch, Gamepad360::B_BUTTON);
    actionMap.map(InputActionId::MenuDown, Gamepad360::DPAD_DOWN);
    actionMap.map(InputActionId::MenuUp, Gamepad360::DPAD_UP);
    actionMap.map(
        InputActionId::MoveUp,
        Gamepad360::LEFT_STICK_Y,
        AxisRange::Negative
    );
    actionMap.map(
        InputActionId::MoveDown,
        Gamepad360::LEFT_STICK_Y,
        AxisRange::Positive
    );
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

    //  Main loop
    while (!glfwWindowShouldClose(window)) {
        inputManager.update();

        //  Display mouse position when it changes
        static Coord lastMousePosition;
        const Coord mousePosition = mouse.getPosition();
        if (mousePosition != lastMousePosition) {
            std::cout
                << mouse.getName() << ": Position "
                << to_string(mousePosition)
                << std::endl;
            lastMousePosition = mousePosition;
        }

        //  Display mouse scroll when it changes
        static Coord lastMouseScroll;
        const Coord mouseScroll = mouse.getScroll();
        if (mouseScroll != Coord(0, 0)) {
            std::cout
                << mouse.getName() << ": Scroll "
                << to_string(mouseScroll)
                << std::endl;
            lastMouseScroll = mouseScroll;
        }

        //  Display mouse left clicks
        if (mouse.isPressed(0)) {
            std::cout
                << mouse.getName() << ": "
                << "Left Button"
                << std::endl;
        }

        //  Display activated input actions for each device
        for (const auto& d : devices) {
            const Device& device = *d;

            if (actionMap.getDigitalValue(InputActionId::Quit, device)) {
                printDigitalAction(InputActionId::Quit, actionMap, device);
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }

            printPressedAction(InputActionId::Accept, actionMap, device);
            printPressedAction(InputActionId::MenuDown, actionMap, device);
            printPressedAction(InputActionId::MenuUp, actionMap, device);

            printDigitalAction(InputActionId::Crouch, actionMap, device);

            // printAnalogAction(InputActionId::Accelerate, actionMap, device);

            printAnalogAction(
                "Move",
                InputActionId::MoveDown,
                InputActionId::MoveUp,
                InputActionId::MoveRight,
                InputActionId::MoveLeft,
                actionMap,
                device
            );
            // printAnalogAction(InputActionId::MoveDown, actionMap, device);
            // printAnalogAction(InputActionId::MoveUp, actionMap, device);
            // printAnalogAction(InputActionId::MoveLeft, actionMap, device);
            // printAnalogAction(InputActionId::MoveRight, actionMap, device);
        }

        //  Update window
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
