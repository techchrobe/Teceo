#include "tcpch.h"
#include "WindowsWindow.h"

#include "Teceo/Events/ApplicationEvent.h"
#include "Teceo/Events/KeyEvent.h"
#include "Teceo/Events/MouseEvent.h"

namespace Teceo {

	static bool _GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* desc) {
		TC_CORE_ERROR("GLFW Error {0}: {1}", error, desc);
	}

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		_data.Title = props.Title;
		_data.Height = props.Height;
		_data.Width = props.Width;

		TC_CORE_INFO("Creating window {0} ({1}, {2})", _data.Title, _data.Width, _data.Height);

		if (!_GLFWInitialized) {
			int success = glfwInit();
			TC_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)_data.Width, (int)_data.Height, _data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);

		glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* window) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(_window, [](GLFWwindow* window, double x, double y) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)x, float(y));
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double x, double y) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)x, float(y));
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Update() {
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		_data.VSync = enabled;
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(_window);
	}
}
