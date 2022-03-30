#include "tcpch.h"
#include "GameObject.h"

namespace Teceo {
	GameObject::~GameObject()
	{
		while (!_components.empty()) {
			deregisterComponent(_components.back());
		}
		_components.clear();
	}

	void GameObject::registerComponent(IComponent::Ptr component)
	{
		const auto it = std::find(_components.begin(), _components.end(), component);
		if (it == _components.end()) {
			_components.push_back(component);
		}
	}

	void GameObject::deregisterComponent(IComponent::Ptr component)
	{
		const auto it = std::find(_components.begin(), _components.end(), component);
		if (it != _components.end()) {
			_components.erase(it);
			component = nullptr;
		}
	}

	bool GameObject::hasComponent(const std::string& comp)
	{
		for (const auto& component : _components) {
			if (component->getType() == comp) { return true; }
		}
		return false;
	}
}
