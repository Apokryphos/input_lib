cmake_minimum_required(VERSION 3.11)

project(input_lib)

set(HEADER_FILES
    include/input_lib/action_id.hpp
    include/input_lib/action_map.hpp
    include/input_lib/axis_range.hpp
    include/input_lib/bimap.hpp
    include/input_lib/button_state.hpp
    include/input_lib/button_state_map.hpp
    include/input_lib/device.hpp
    include/input_lib/device_type.hpp
    include/input_lib/gamepad.hpp
    include/input_lib/gamepad_360.hpp
    include/input_lib/gamepad_action_map.hpp
    include/input_lib/gamepad_axis.hpp
    include/input_lib/gamepad_button.hpp
    include/input_lib/input_manager.hpp
    include/input_lib/input_type.hpp
    include/input_lib/key.hpp
    include/input_lib/key_state.hpp
    include/input_lib/key_state_map.hpp
    include/input_lib/keyboard.hpp
    include/input_lib/keyboard_action_map.hpp
    include/input_lib/mouse.hpp
    include/input_lib/mouse_action_map.hpp
    include/input_lib/mouse_button.hpp
    include/input_lib/point.hpp
    include/input_lib/to_string.hpp
)

set(SOURCE_FILES
    src/action_map.cpp
    src/gamepad_action_map.cpp
    src/keyboard_action_map.cpp
    src/mouse_action_map.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${INPUT_LIB_VERSION}
)

include_directories(include)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${input_lib_include_dest}>
    $<INSTALL_INTERFACE:${input_lib_lib_dest}>
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    DESTINATION ${input_lib_lib_dest}
    PUBLIC_HEADER DESTINATION ${input_lib_include_dest}/input_lib
)

#install(FILES ${PROJECT_NAME}-config.cmake DESTINATION ${input_lib_lib_main_dest})

install(EXPORT ${PROJECT_NAME} DESTINATION "${input_lib_lib_dest}")
