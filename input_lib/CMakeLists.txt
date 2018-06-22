cmake_minimum_required(VERSION 3.11)

project(input_lib)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)
