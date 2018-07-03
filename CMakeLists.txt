cmake_minimum_required(VERSION 3.11)


#   ----------------------------------------------------------------------------
#   Version
#   ----------------------------------------------------------------------------
set(INPUT_LIB_VERSION_MAJOR 0 CACHE STRING "major version" FORCE)
set(INPUT_LIB_VERSION_MINOR 1 CACHE STRING "minor version" FORCE)
set(INPUT_LIB_VERSION
    ${INPUT_LIB_VERSION_MAJOR}.${INPUT_LIB_VERSION_MINOR}
    CACHE STRING "version"
    FORCE
)

#   ----------------------------------------------------------------------------
#   input_lib
#   ----------------------------------------------------------------------------
set(input_lib_include_dest
    "include/input_lib-${INPUT_LIB_VERSION}"
)

set(input_lib_lib_main_dest
    "lib/input_lib-${INPUT_LIB_VERSION}"
)

set(input_lib_lib_dest
    "${input_lib_lib_main_dest}/${CMAKE_BUILD_TYPE}"
)

configure_file(input_lib-version.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/input_lib-config-version.cmake
    @ONLY
)

install(FILES input_lib-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/input_lib-config-version.cmake
    DESTINATION ${input_lib_lib_main_dest}
)

add_subdirectory(input_lib)


#   ----------------------------------------------------------------------------
#   input_lib_glfw
#   ----------------------------------------------------------------------------
set(input_lib_glfw_include_dest
    "include/input_lib_glfw-${INPUT_LIB_VERSION}"
)

set(input_lib_glfw_lib_main_dest
    "lib/input_lib_glfw-${INPUT_LIB_VERSION}"
)

set(input_lib_glfw_lib_dest
    "${input_lib_glfw_lib_main_dest}/${CMAKE_BUILD_TYPE}"
)

configure_file(input_lib-version.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/input_lib_glfw-config-version.cmake
    @ONLY
)

install(FILES input_lib_glfw-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/input_lib_glfw-config-version.cmake
    DESTINATION ${input_lib_glfw_lib_main_dest}
)

add_subdirectory(input_lib_glfw)

#   ----------------------------------------------------------------------------
#   Demo
#   ----------------------------------------------------------------------------
option(BUILD_INPUT_LIB_DEMO "Build InputLib demo" ON)

if (BUILD_INPUT_LIB_DEMO)
    add_subdirectory(extlibs)
    add_subdirectory(input_lib_demo)
endif(BUILD_INPUT_LIB_DEMO)
