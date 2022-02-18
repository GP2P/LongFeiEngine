#ifndef DF_EVENTKEYBOARD_H
#define DF_EVENTKEYBOARD_H

#include "Event.h"

namespace df {

	const std::string KEYBOARD_EVENT = "df-keyboard";
	// Types of keyboard actions Dragonfly recognizes.
	enum EventKeyboardAction {
		UNDEFINED_ACTION = -1,
		KEY_PRESSED,
		KEY_RELEASED,
		KEY_DOWN,
	};

	// Keyboard namespace.
	namespace Keyboard {
		// Keys Dragonfly recognizes.
		enum Key {
			UNDEFINED_KEY = -1,
			SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW, UPARROW, DOWNARROW,
			PAUSE, MINUS, PLUS, TILDE, PERIOD, COMMA, SLASH,
			EQUAL, BACKSLASH, MULTIPLY, QUOTE, SEMICOLON,
			LEFTCONTROL, RIGHTCONTROL,
			LEFTSHIFT, RIGHTSHIFT, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
			A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9, NUM0, BACKSPACE,
		};
	}

	class EventKeyboard : public Event {

	private:

		Keyboard::Key keyValue;
		EventKeyboardAction keyAction;

	public:

		EventKeyboard();

		EventKeyboard(Keyboard::Key key, EventKeyboardAction action);

		virtual void setKey(Keyboard::Key key);

		virtual Keyboard::Key getKey() const;

		virtual void setKeyboardAction(EventKeyboardAction action);

		virtual EventKeyboardAction getKeyboardAction() const;
	};
}

#endif //DF_EVENTKEYBOARD_H
