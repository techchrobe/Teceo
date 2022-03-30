#pragma once
#include "IState.h"

namespace Teceo {
	// Class for testing states
	class TestState : public IState
	{
	public:
		TestState() {};
		void init() override;
		void update(float deltaTime) override;
		void exit() override;
	};
}

