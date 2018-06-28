cmake_minimum_required(VERSION 3.11)

find_package(glfw3 REQUIRED)

project(input_lib_glfw)

set(SOURCE_FILES
    src/glfw_gamepad.cpp
    src/glfw_input_manager.cpp
    src/glfw_key_map.cpp
    src/glfw_keyboard.cpp
    src/glfw_mouse.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} glfw input_lib)
