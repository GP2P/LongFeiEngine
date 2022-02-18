#ifndef DF_EVENTMOUSE_H
#define DF_EVENTMOUSE_H

#include "Event.h"
#include "Vector.h"

namespace df {
	const std::string MSE_EVENT = "df-mouse";

	// Set of mouse actions recognized by Dragonfly.
	enum EventMouseAction {
		UNDEFINED_MOUSE_ACTION = -1,
		CLICKED,
		PRESSED,
		MOVED,
	};

	// Set of mouse buttons recognized by Dragonfly.

	namespace Mouse {
		enum Button {
			UNDEFINED_MOUSE_BUTTON = -1,
			LEFT,
			RIGHT,
			MIDDLE,
		};
	}

	class EventMouse : public Event {


	private:

		EventMouseAction mouseAction;

		Mouse::Button mouseButton;

		Vector mousePos;

	public:

		EventMouse();

		EventMouse(EventMouseAction action, Mouse::Button button, Vector mouse_xy);

		// Get mouse event's action.
		EventMouseAction getMouseAction() const;

		// Set mouse event's action.
		void setMouseAction(EventMouseAction action);

		// Get mouse event's button.
		Mouse::Button getMouseButton() const;

		// Set mouse event's button.
		void setMouseButton(Mouse::Button button);

		// Get mouse event's position.
		Vector getMousePosition() const;

		// Set mouse event's position.
		void setMousePosition(Vector position);
	};
}

#endif //DF_EVENTMOUSE_H
