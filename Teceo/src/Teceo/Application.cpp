#include "tcpch.h"

#include "Application.h"
#include "Teceo/Log.h"
#include "States/StateManager.h"

#include <GLFW/glfw3.h>

#include <chrono>
using namespace std::chrono;

namespace Teceo {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {

	}

	void Application::onEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(windowClose));

		TC_CORE_TRACE("{0}", event);
	}

	bool Application::windowClose(WindowCloseEvent& event)
	{
		_running = false;
		return true;
	}

	bool Application::init() {
		WindowResizeEvent e(1280, 720);
		TC_TRACE(e);
		_running = true;

		StateManager::getInstance().registerState("test", _test);
		StateManager::getInstance().setState("test");

		return true;
	}

	float getMilliseconds() {
		return system_clock::now().time_since_epoch().count();
	}

	void Application::Run() {
		if (!init())
			return;

		float lastTick = getMilliseconds();
		float deltaTime = 0;
		while (_running) {
			deltaTime = (getMilliseconds() - lastTick);
			lastTick = getMilliseconds();

			update(deltaTime);
		}

		shutdown();
	}

	void Application::update(float deltaTime)
	{
		_window->Update();
		glClearColor(0, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		StateManager::getInstance().update(deltaTime);
	}

	void Application::shutdown()
	{
		StateManager::getInstance().cleanUp();
	}
}