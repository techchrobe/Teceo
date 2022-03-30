#pragma once
#include "Teceo/GameObjects/GameObjectManager.h"

namespace Teceo {
	// easy access of GameObjectManager Ptr
	typedef std::shared_ptr<GameObjectManager> GameObjectManagerPtr;

	// Interface for game states
	class IState {
	public:
		virtual ~IState() {};

		// Basic game loop functionallity
		virtual void init() = 0;
		virtual void update(float deltaTime) = 0;
		// TODO: Add render()
		virtual void exit() = 0;
	protected:
		bool _isInstantiated = false;
		GameObjectManagerPtr _gameObjectManager;
		// Would also contain Render and Physics Manager
	};
}