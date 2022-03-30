#include "tcpch.h"
#include "TestState.h"
#include "Teceo/GameObjects/TestComponent.h"

namespace Teceo {
	void TestState::init()
	{
		_gameObjectManager = std::make_shared<GameObjectManager>();

		auto newGO = std::make_shared<GameObject>("TestGO", 50, 50);
		TC_CORE_INFO("Initializing " + newGO->getId());
		auto newComponent = std::make_shared<TestComponent>(*newGO, "testing...");
		newGO->registerComponent(newComponent);

		_gameObjectManager->addGameObject(newGO);
	}

	void TestState::update(float deltaTime)
	{
		_gameObjectManager->update(deltaTime);
	}

	void TestState::exit()
	{
		_isInstantiated = false;
		_gameObjectManager->shutdown();
	}
}
