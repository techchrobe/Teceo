#pragma once
#include "IComponent.h"

namespace Teceo {
	// A Test component that prints a message on update
	class TestComponent : IComponent
	{
	public:
		TestComponent(GameObject& gameObject, std::string message) : _message(message), IComponent(gameObject) {}
		void update();
	private:
		std::string _message;
	};
}

