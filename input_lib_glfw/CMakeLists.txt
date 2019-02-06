cmake_minimum_required(VERSION 3.11)

find_package(glfw3 REQUIRED)

project(input_lib_glfw)

set(HEADER_FILES
    include/input_lib/glfw/glfw_gamepad.hpp
    include/input_lib/glfw/glfw_input_manager.hpp
    include/input_lib/glfw/glfw_key_map.hpp
    include/input_lib/glfw/glfw_keyboard.hpp
    include/input_lib/glfw/glfw_mouse.hpp
)

set(SOURCE_FILES
    src/glfw_gamepad.cpp
    src/glfw_input_manager.cpp
    src/glfw_key_map.cpp
    src/glfw_keyboard.cpp
    src/glfw_mouse.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${INPUT_LIB_VERSION}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${input_lib_glfw_include_dest}>
    $<INSTALL_INTERFACE:${input_lib_glfw_lib_dest}>
)

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_DL_LIBS} glfw input_lib)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    DESTINATION ${input_lib_glfw_lib_dest}
    PUBLIC_HEADER DESTINATION ${input_lib_glfw_include_dest}/input_lib/glfw
)

#install(FILES ${PROJECT_NAME}-config.cmake DESTINATION ${input_lib_glfw_lib_main_dest})

install(EXPORT ${PROJECT_NAME} DESTINATION "${input_lib_glfw_lib_dest}")
