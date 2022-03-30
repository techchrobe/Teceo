#pragma once
#include <memory>
#include <string>

namespace Teceo {
	// predefine GameObjects so they can be accessed in the Components
	class GameObject;

	// Interface for Component types that can be added to Game Objects
	class IComponent
	{
	public:
		// For easy access of shared and weak Pointers
		using Ptr = std::shared_ptr<IComponent>;
		using WPtr = std::weak_ptr<IComponent>;

		explicit IComponent(GameObject& gameObject) : _gameObject(gameObject) {}

		virtual ~IComponent() = default;

		GameObject& _gameObject;

		virtual void update(float deltaTime) = 0;

		// Returns the Component type
		[[nodiscard]] std::string getType() const { return static_cast<std::string>(typeid(*this).name()).substr(6, std::string::npos); }
	};
}
