#include "tcpch.h"
#include "StateManager.h"

namespace Teceo {
	StateManager& StateManager::getInstance()
	{
		static StateManager _instance;

		return _instance;
	}

	void StateManager::registerState(std::string name, IState* state)
	{
		this->_states.insert(std::pair<std::string, IState*>(name, state));
	}

	void StateManager::update(float deltaTime)
	{
		this->_currentState->update(deltaTime);
	}

	// When switching states call exit on the current state and init on the next state
	void StateManager::setState(std::string stateName)
	{
		if (this->_currentState != _states[stateName]) {
			if (_currentState != nullptr) {
				_currentState->exit();
			}
			this->_currentState = _states[stateName];
			this->_currentState->init();
		}
	}

	void StateManager::cleanUp()
	{
		_currentState->exit();
		for (auto const& [key, val] : _states) {
			delete val;
		}

		_states.clear();
	}
}
