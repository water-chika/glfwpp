cmake_minimum_required(VERSION 3.20)

project(glfwpp)

add_subdirectory(glfw)

add_library(glfwpp
    glfwpp.hpp
    glfwpp.cpp)

target_link_libraries(glfwpp PUBLIC glfw)
