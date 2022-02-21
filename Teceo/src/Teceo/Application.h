#pragma once

#include "Core.h"

namespace Teceo {

	class TECEO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}
