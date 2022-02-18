#include "EventKeyboard.h"

df::EventKeyboard::EventKeyboard() {
	keyValue = Keyboard::UNDEFINED_KEY;
	keyAction = UNDEFINED_ACTION;
	setType(KEYBOARD_EVENT);
}

df::EventKeyboard::EventKeyboard(df::Keyboard::Key key, df::EventKeyboardAction action) {
	keyValue = key;
	keyAction = action;
	setType(KEYBOARD_EVENT);
}

void df::EventKeyboard::setKey(df::Keyboard::Key key) {
	keyValue = key;
}

df::Keyboard::Key df::EventKeyboard::getKey() const {
	return keyValue;
}

void df::EventKeyboard::setKeyboardAction(df::EventKeyboardAction action) {
	keyAction = action;
}

df::EventKeyboardAction df::EventKeyboard::getKeyboardAction() const {
	return keyAction;
}
