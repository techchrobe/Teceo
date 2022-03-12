#include "tcpch.h"

#include "Application.h"
#include "Teceo/Events/ApplicationEvent.h"
#include "Teceo/Log.h"

namespace Teceo {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		TC_TRACE(e);
		while (true);
	}
}