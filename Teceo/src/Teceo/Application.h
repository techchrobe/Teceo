#pragma once

#include "Core.h"
#include "Teceo/Events/Event.h"
#include "Teceo/Events/ApplicationEvent.h"
#include <Teceo/Window.h>

namespace Teceo {

	class TECEO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);
	private:
		bool WindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in client
	Application* CreateApplication();
}
