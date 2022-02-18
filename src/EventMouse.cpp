#include "EventMouse.h"

df::EventMouse::EventMouse() {
	mouseAction = UNDEFINED_MOUSE_ACTION;
	mouseButton = Mouse::UNDEFINED_MOUSE_BUTTON;
	mousePos = Vector();
	setType(MSE_EVENT);
}

df::EventMouse::EventMouse(df::EventMouseAction action, df::Mouse::Button button, df::Vector mouse_xy) {
	mouseAction = action;
	mouseButton = button;
	mousePos = mouse_xy;
	setType(MSE_EVENT);
}

df::EventMouseAction df::EventMouse::getMouseAction() const {
	return mouseAction;
}

void df::EventMouse::setMouseAction(df::EventMouseAction action) {
	mouseAction = action;
}

df::Mouse::Button df::EventMouse::getMouseButton() const {
	return mouseButton;
}

void df::EventMouse::setMouseButton(df::Mouse::Button button) {
	mouseButton = button;
}

df::Vector df::EventMouse::getMousePosition() const {
	return mousePos;
}

void df::EventMouse::setMousePosition(df::Vector new_mouse_xy) {
	mousePos = new_mouse_xy;
}
