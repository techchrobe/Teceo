#include "tcpch.h"
#include "GameObjectManager.h"

namespace Teceo {
	void GameObjectManager::init()
	{
		// empty for now
		// can be used for initializing event listeners
	}

	void GameObjectManager::shutdown()
	{
		_gameObjects.clear();
	}

	// Adds a GO that doesn't exist yet
	void GameObjectManager::addGameObject(const GameObject::Ptr gameObject)
	{
		TC_CORE_ASSERT(_gameObjects.find(gameObject->getId()) == _gameObjects.end(),
			"Game object with this _id already exists " + gameObject->getId());

		_gameObjects[gameObject->getId()] = gameObject;
	}

	// Removes a specific GO
	void GameObjectManager::removeGameObject(const GameObject::Ptr gameObject)
	{
		_gameObjects.erase(gameObject->getId());
	}

	// Returns a GO based on the id
	GameObject::Ptr GameObjectManager::getGameObject(const std::string& id) const
	{
		const auto it = _gameObjects.find(id);
		if (it == _gameObjects.end()) {
			TC_CORE_ASSERT("Could not find gameobject with m_id " + id);
			return nullptr;
		}
		return it->second;
	}

	void GameObjectManager::update(float deltaTime)
	{
		// Update all components linked to the existing Game Objects
		for (auto const& [key, val] : _gameObjects) {
			for (IComponent::Ptr com : val->getComponents()) {
				com->update(deltaTime);
			}
		}

		// Safely remove GOs that are marked for removal
		auto tmp = std::vector<GameObject::Ptr>();
		for (auto g : _gameObjects) {
			if (g.second->isMarkedForDelete()) {
				tmp.push_back(g.second);
			}
		}
		for (auto g : tmp) {
			removeGameObject(g);
		}
	}
}
