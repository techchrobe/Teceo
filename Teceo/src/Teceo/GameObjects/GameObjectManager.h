#pragma once
#include "GameObject.h"

namespace Teceo {

	// Singleton for managing multiple Game Objects
	class GameObjectManager
	{
	public:
		// For easy access of and string, GameObject Ptr unordered map
		using GameObjectMap = std::unordered_map<std::string, GameObject::Ptr>;

		GameObjectManager() {
			init();
		}
		void init();
		void shutdown();

		// Handle Game Objects (adding, removing, finding)
		void addGameObject(const GameObject::Ptr gameObject);
		void removeGameObject(const GameObject::Ptr gameObject);
		[[nodiscard]] GameObject::Ptr getGameObject(const std::string& id) const;

		// Used for updating the components of the GO
		void update(float deltaTime);

		// Returns all GOs
		GameObjectMap& getGameObjects() { return _gameObjects; }

	private:
		GameObjectMap _gameObjects;
	};
}

