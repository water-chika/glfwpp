#include "glfwpp.hpp"
#include <cassert>

// used for Debug.
static bool is_inited = false;

bool glfwpp::init() {
	assert(!is_inited);
	is_inited = glfwInit();
	return is_inited;
}

void glfwpp::terminate() {
	assert(is_inited);
	is_inited = false;
	glfwTerminate();
}

void glfwpp::window_hint(int hint, int value) {
	glfwWindowHint(hint, value);
}

GLFWwindow* glfwpp::create_window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
	return glfwCreateWindow(width, height, title, monitor, share);
}

void glfwpp::destroy_window(GLFWwindow* window) {
	glfwDestroyWindow(window);
}

VkResult glfwpp::create_surface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface) {
	return glfwCreateWindowSurface(instance, window, allocator, surface);
}

bool glfwpp::window_should_close(GLFWwindow* window) {
	return glfwWindowShouldClose(window);
}

void glfwpp::poll_events() {
	glfwPollEvents();
}
