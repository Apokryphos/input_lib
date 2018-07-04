#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//  ----------------------------------------------------------------------------
static void error_callback(int error, const char* description) {
    std::cerr << "OpenGL Error: " << description << std::endl;
}

//  ----------------------------------------------------------------------------
GLFWwindow* initializeGlfw(const int width, const int height) {
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        std::cerr << "GLFW failed to initialize." << std::endl;
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(width, height, "InputLib Demo", NULL, NULL);

    if (window == NULL) {
        std::cerr << "GLFW failed to create window." << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    //  glad
    if (!gladLoadGL()) {
        std::cerr << "Glad failed to initialize." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return NULL;
    }

    return window;
}

//  ----------------------------------------------------------------------------
void shutdownGlfw(GLFWwindow* window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

//  ----------------------------------------------------------------------------
void updateWindow(GLFWwindow* window) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}
