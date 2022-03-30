#pragma once
#include "IComponent.h"
#include "GameObject.h"

namespace Teceo {
	// A Test component that prints a message on update
	class TestComponent : public IComponent
	{
	public:
		explicit TestComponent(GameObject& gameObject, std::string message) : IComponent(gameObject), _message(message) {}
		void update(float deltaTime) override;
	private:
		std::string _message;
	};
}

