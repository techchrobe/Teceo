#include "tcpch.h"

#include "Application.h"
#include "Teceo/Log.h"

#include <GLFW/glfw3.h>

namespace Teceo {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(WindowClose));

		TC_CORE_TRACE("{0}", event);
	}

	bool Application::WindowClose(WindowCloseEvent& event)
	{
		_running = false;
		return true;
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