#include <glad/glad.h>
#include "input_lib/glfw/glfw_input_manager.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace InputLib;

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

    const int ACTION_QUIT = 0;

    auto& keyboard = inputManager.getKeyboard();

    Action quitAction = {};
    quitAction.id = ACTION_QUIT;
    quitAction.type = ActionType::Digital;

    keyboard.bind(quitAction, Key::Escape);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        auto& keyboard = inputManager.getKeyboard();

        if (keyboard.getDigitalValue(quitAction)) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
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
