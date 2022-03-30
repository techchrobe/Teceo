#pragma once

#include "Core.h"
#include "Teceo/Events/Event.h"
#include "Teceo/Events/ApplicationEvent.h"
#include <Teceo/Window.h>
#include "States/TestState.h"

namespace Teceo {

	class TECEO_API Application
	{
	public:
		Application();
		virtual ~Application();

		bool init();
		void Run();
		void update(float deltaTime);
		void onEvent(Event& event);
		void shutdown();
	private:
		bool windowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> _window;
		bool _running = true;
		TestState* _test = new TestState();
	};

	// To be defined in client
	Application* CreateApplication();
}
