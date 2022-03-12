#include "tcpch.h"
#include "WindowsWindow.h"

namespace Teceo {

	static bool _GLFWInitialized = false;

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

			_GLFWInitialized = true;
		}

		_window = glfwCreateWindow((int)_data.Width, (int)_data.Height, _data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);
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
