#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <cassert>

namespace glfwpp {
	bool init();
	void terminate();
	void window_hint(int hint, int value);
	GLFWwindow* create_window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	void destroy_window(GLFWwindow* window);
	VkResult create_surface(VkInstance instance, GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
	bool window_should_close(GLFWwindow* window);
	void poll_events();
	class window {
	public:
		void create(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
			m_window = create_window(width, height, title, monitor, share);
		}
		void destroy() {
			destroy_window(m_window);
		}
		bool should_close() {
			return window_should_close(m_window);
		}
		operator GLFWwindow* () {
			return m_window;
		}
	private:
		GLFWwindow* m_window;
	};
}