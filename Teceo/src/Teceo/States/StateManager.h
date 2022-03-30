#pragma once
#include "IState.h"
#include <map>

namespace Teceo {
	// Singleton for managing and switching between different states
	class StateManager
	{
	public:
		static StateManager& getInstance();

		void registerState(std::string name, IState* state);

		void update(float deltaTime);
		void setState(std::string stateName);
		void cleanUp();

	private:
		StateManager() = default;
		~StateManager(void) = default;
		IState* _currentState = nullptr;

		std::map<std::string, IState*> _states;
	};
}

