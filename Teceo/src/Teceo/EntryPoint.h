#pragma once

#ifdef  TC_PLATFORM_WINDOWS

extern Teceo::Application* Teceo::CreateApplication();

int main(int argc, char** argv) {
	Teceo::Log::Init();
	TC_CORE_WARN("Initialized Log!");
	TC_INFO("Hello");

	auto app = Teceo::CreateApplication();
	app->Run();
	delete app;
}

#endif //  TC_PLATFORM_WINDOWS
