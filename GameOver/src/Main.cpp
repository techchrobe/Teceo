#include <Teceo.h>

class GameOver : public Teceo::Application {
public:
	GameOver() {

	}

	~GameOver() {

	}
};

Teceo::Application* Teceo::CreateApplication() {
	return new GameOver();
}