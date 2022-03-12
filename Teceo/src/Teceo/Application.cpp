#include "tcpch.h"

#include "Application.h"
#include "Teceo/Events/ApplicationEvent.h"
#include "Teceo/Log.h"

#include <GLFW/glfw3.h>

namespace Teceo {

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		TC_TRACE(e);
		while (_running) {
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->Update();
		}
	}
}