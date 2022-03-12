#pragma once

#include "Event.h"

namespace Teceo {
	class TECEO_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : _x(x), _y(y) {}

		inline float GetX() const { return _x; }
		inline float GetY() const { return _y; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _x << ", " << _y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _x;
		float _y;
	};

	class TECEO_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float x, float y) : _x(x), _y(y) {}

		inline float GetX() const { return _x; }
		inline float GetY() const { return _y; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _x << ", " << _y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _x;
		float _y;
	};

	class TECEO_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return _button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button) : _button(button) {}

		int _button;
	};

	class TECEO_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class TECEO_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}