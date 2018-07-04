cmake_minimum_required(VERSION 3.11)

project(input_lib_demo)

set(SOURCE_FILES
    src/glfw.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} input_lib_glfw glad)
