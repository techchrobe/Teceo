#pragma once

#include "Teceo/Window.h"
#include <GLFW/glfw3.h>

namespace Teceo {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void Update() override;

		inline unsigned int GetWidth() const override { return _data.Width; }
		inline unsigned int GetHeight() const override { return _data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return _data.VSync; };

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* _window;
		struct WindowData {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData _data;
	};
}
