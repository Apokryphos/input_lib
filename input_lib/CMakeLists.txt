cmake_minimum_required(VERSION 3.11)

project(input_lib)

set(SOURCE_FILES
    src/action_map.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(include)

target_include_directories(${PROJECT_NAME} INTERFACE include)
