#include "tcpch.h"
#include "TestComponent.h"
#include "GameObject.h"

namespace Teceo {
	void Teceo::TestComponent::update(float deltaTime)
	{
		TC_CORE_INFO(getType() + " of Game Object " + _gameObject.getId() + " says: " + _message);
	}
}
