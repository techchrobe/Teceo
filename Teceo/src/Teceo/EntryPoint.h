#pragma once

#ifdef  TC_PLATFORM_WINDOWS

extern Teceo::Application* Teceo::CreateApplication();

int main(int argc, char** argv) {
	printf("Game is Running...");
	auto app = Teceo::CreateApplication();
	app->Run();
	delete app;
}

#endif //  TC_PLATFORM_WINDOWS
