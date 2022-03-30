#include "tcpch.h"
#include "TestComponent.h"
#include "GameObject.h"

void Teceo::TestComponent::update()
{
	TC_CORE_INFO(getType() + " of Game Object " + _gameObject.getId() + " says: " + _message);
}
