#pragma once
#include <vector>
#include <string>
#include "IComponent.h"

namespace Teceo {

	// Position of the Game Object
	struct Position {
		unsigned int x;
		unsigned int y;
	};

	// Component based Game Object class
	class GameObject
	{
	public:
		// For easy access of shared and weak Pointers
		using Ptr = std::shared_ptr<GameObject>;
		using WPtr = std::weak_ptr<GameObject>;

		GameObject(std::string name) : _id(name) {
			_position.x = 0;
			_position.y = 0;
		};
		GameObject(std::string name, int posX, int posY) : _id(name) {
			_position.x = posX;
			_position.y = posY;
		};
		~GameObject();

		// used for adding and removing different components to the game object
		void registerComponent(IComponent::Ptr component);
		void deregisterComponent(IComponent::Ptr component);

		// used for checking components of the game object (for example if the GO has a collider)
		bool hasComponent(const std::string& comp);
		std::vector<IComponent::Ptr> getComponents() const { return _components; }

		Position getPosition() { return _position; }
		void setPosition(Position newPos) { _position = newPos; }
		std::string getId() const { return _id; };

		// used for marking the GO for a safe deletion
		bool isMarkedForDelete() const { return _markedForDeletes; }
		void markForDelete() { _markedForDeletes = true; }

		template <typename TComponent>
		std::shared_ptr<TComponent> getComponent() {
			for (auto component : _components) {
				std::dynamic_pointer_cast<TComponent>(component);
				if (std::shared_ptr<TComponent> cmp = std::dynamic_pointer_cast<TComponent>(component)) {
					return cmp;
				}
			}
			return nullptr;
		}
	private:
		std::string _id;
		Position _position;
		std::vector<IComponent::Ptr> _components;
		bool _markedForDeletes = false;
	};
}

