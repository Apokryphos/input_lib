#include <glad/glad.h>
#include "input_lib/glfw/glfw_input_manager.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace InputLib;

enum class InputActionId
{
    Accept,
    MoveUp,
    Quit,
};

class InputActions
{
static void makeDigital(Action& action, const InputActionId actionId) {
    action.id = static_cast<int>(actionId);
    action.type = ActionType::Digital;
}

public:
    static Action Accept;
    static Action Quit;
    static Action MoveUp;

    static void initialize() {
        makeDigital(Accept, InputActionId::Accept);
        makeDigital(MoveUp, InputActionId::MoveUp);
        makeDigital(Quit, InputActionId::Quit);
    }
};

Action InputActions::Accept = {};
Action InputActions::Quit = {};
Action InputActions::MoveUp = {};

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

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cerr << "Glad failed to initialize." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        throw std::runtime_error("GLAD failed to initialize.");
    }

    GlfwInputManager inputManager;

    auto& keyboard = inputManager.getKeyboard();

    InputActions::initialize();
    keyboard.bind(InputActions::Accept, Key::Enter);
    keyboard.bind(InputActions::MoveUp, Key::Up);
    keyboard.bind(InputActions::Quit, Key::Escape);

    while (!glfwWindowShouldClose(window)) {
        inputManager.update();

        auto& keyboard = inputManager.getKeyboard();

        if (keyboard.getDigitalValue(InputActions::Quit)) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        if (keyboard.isPressed(InputActions::Accept)) {
            std::cout << "ACCEPT" << std::endl;
        }

        if (keyboard.getDigitalValue(InputActions::MoveUp)) {
            std::cout << "MOVE UP" << std::endl;
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
