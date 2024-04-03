cmake_minimum_required(VERSION 3.20)

project(glfwpp)

add_subdirectory(glfw)

find_package(Vulkan REQUIRED)

add_library(glfwpp
    glfwpp.hpp
    glfwpp.cpp)

target_link_libraries(glfwpp PUBLIC glfw Vulkan::Vulkan)
target_include_directories(glfwpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
