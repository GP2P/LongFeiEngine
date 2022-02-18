#include "InputManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "LogManager.h"

df::InputManager::InputManager() {
	setType("InputManager");
}

df::InputManager &df::InputManager::getInstance() {
	static InputManager instance;
	return instance;
}

int df::InputManager::startUp() {
	if (!DM.isStarted())
		return -1;

	DM.getWindow()->setKeyRepeatEnabled(false);

	LM.writeLog(1, "InputManager::startUp(): InputManager started successfully");
	return Manager::startUp();
}

void df::InputManager::shutDown() {
	DM.getWindow()->setKeyRepeatEnabled(true);
	Manager::shutDown();
}

void df::InputManager::getInput() {
	sf::Event event;
	while (DM.getWindow()->pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
			EventKeyboard keyEvent;

			if (event.type == sf::Event::KeyPressed)
				keyEvent.setKeyboardAction(KEY_PRESSED);
			else if (event.type == sf::Event::KeyReleased)
				keyEvent.setKeyboardAction(KEY_RELEASED);

			switch (event.key.code) {
				case sf::Keyboard::W:
					keyEvent.setKey(Keyboard::W);
					break;
				case sf::Keyboard::A:
					keyEvent.setKey(Keyboard::A);
					break;
				case sf::Keyboard::B:
					keyEvent.setKey(Keyboard::B);
					break;
				case sf::Keyboard::C:
					keyEvent.setKey(Keyboard::C);
					break;
				case sf::Keyboard::D:
					keyEvent.setKey(Keyboard::D);
					break;
				case sf::Keyboard::E:
					keyEvent.setKey(Keyboard::E);
					break;
				case sf::Keyboard::F:
					keyEvent.setKey(Keyboard::F);
					break;
				case sf::Keyboard::G:
					keyEvent.setKey(Keyboard::G);
					break;
				case sf::Keyboard::H:
					keyEvent.setKey(Keyboard::H);
					break;
				case sf::Keyboard::I:
					keyEvent.setKey(Keyboard::I);
					break;
				case sf::Keyboard::J:
					keyEvent.setKey(Keyboard::J);
					break;
				case sf::Keyboard::K:
					keyEvent.setKey(Keyboard::K);
					break;
				case sf::Keyboard::L:
					keyEvent.setKey(Keyboard::L);
					break;
				case sf::Keyboard::M:
					keyEvent.setKey(Keyboard::M);
					break;
				case sf::Keyboard::N:
					keyEvent.setKey(Keyboard::N);
					break;
				case sf::Keyboard::O:
					keyEvent.setKey(Keyboard::O);
					break;
				case sf::Keyboard::P:
					keyEvent.setKey(Keyboard::P);
					break;
				case sf::Keyboard::Q:
					keyEvent.setKey(Keyboard::Q);
					break;
				case sf::Keyboard::R:
					keyEvent.setKey(Keyboard::R);
					break;
				case sf::Keyboard::S:
					keyEvent.setKey(Keyboard::S);
					break;
				case sf::Keyboard::T:
					keyEvent.setKey(Keyboard::T);
					break;
				case sf::Keyboard::U:
					keyEvent.setKey(Keyboard::U);
					break;
				case sf::Keyboard::V:
					keyEvent.setKey(Keyboard::V);
					break;
				case sf::Keyboard::X:
					keyEvent.setKey(Keyboard::X);
					break;
				case sf::Keyboard::Y:
					keyEvent.setKey(Keyboard::Y);
					break;
				case sf::Keyboard::Z:
					keyEvent.setKey(Keyboard::Z);
					break;
				case sf::Keyboard::Num0:
				case sf::Keyboard::Numpad0:
					keyEvent.setKey(Keyboard::NUM0);
					break;
				case sf::Keyboard::Num1:
				case sf::Keyboard::Numpad1:
					keyEvent.setKey(Keyboard::NUM1);
					break;
				case sf::Keyboard::Num2:
				case sf::Keyboard::Numpad2:
					keyEvent.setKey(Keyboard::NUM2);
					break;
				case sf::Keyboard::Num3:
				case sf::Keyboard::Numpad3:
					keyEvent.setKey(Keyboard::NUM3);
					break;
				case sf::Keyboard::Num4:
				case sf::Keyboard::Numpad4:
					keyEvent.setKey(Keyboard::NUM4);
					break;
				case sf::Keyboard::Num5:
				case sf::Keyboard::Numpad5:
					keyEvent.setKey(Keyboard::NUM5);
					break;
				case sf::Keyboard::Num6:
				case sf::Keyboard::Numpad6:
					keyEvent.setKey(Keyboard::NUM6);
					break;
				case sf::Keyboard::Num7:
				case sf::Keyboard::Numpad7:
					keyEvent.setKey(Keyboard::NUM7);
					break;
				case sf::Keyboard::Num8:
				case sf::Keyboard::Numpad8:
					keyEvent.setKey(Keyboard::NUM8);
					break;
				case sf::Keyboard::Num9:
				case sf::Keyboard::Numpad9:
					keyEvent.setKey(Keyboard::NUM9);
					break;
				case sf::Keyboard::Escape:
					keyEvent.setKey(Keyboard::ESCAPE);
					break;
				case sf::Keyboard::LControl:
					keyEvent.setKey(Keyboard::LEFTCONTROL);
					break;
				case sf::Keyboard::LShift:
					keyEvent.setKey(Keyboard::LEFTSHIFT);
					break;
				case sf::Keyboard::RControl:
					keyEvent.setKey(Keyboard::RIGHTCONTROL);
					break;
				case sf::Keyboard::RShift:
					keyEvent.setKey(Keyboard::RIGHTSHIFT);
					break;
				case sf::Keyboard::Comma:
					keyEvent.setKey(Keyboard::COMMA);
					break;
				case sf::Keyboard::Period:
					keyEvent.setKey(Keyboard::PERIOD);
					break;
				case sf::Keyboard::Quote:
					keyEvent.setKey(Keyboard::QUOTE);
					break;
				case sf::Keyboard::Semicolon:
					keyEvent.setKey(Keyboard::SEMICOLON);
					break;
				case sf::Keyboard::Slash:
					keyEvent.setKey(Keyboard::SLASH);
					break;
				case sf::Keyboard::Backslash:
					keyEvent.setKey(Keyboard::BACKSLASH);
					break;
				case sf::Keyboard::Tilde:
					keyEvent.setKey(Keyboard::TILDE);
					break;
				case sf::Keyboard::Equal:
					keyEvent.setKey(Keyboard::EQUAL);
					break;
				case sf::Keyboard::Space:
					keyEvent.setKey(Keyboard::SPACE);
					break;
				case sf::Keyboard::Enter:
					keyEvent.setKey(Keyboard::RETURN);
					break;
				case sf::Keyboard::Backspace:
					keyEvent.setKey(Keyboard::BACKSPACE);
					break;
				case sf::Keyboard::Tab:
					keyEvent.setKey(Keyboard::TAB);
					break;
				case sf::Keyboard::Add:
					keyEvent.setKey(Keyboard::PLUS);
					break;
				case sf::Keyboard::Subtract:
					keyEvent.setKey(Keyboard::MINUS);
					break;
				case sf::Keyboard::Multiply:
					keyEvent.setKey(Keyboard::MULTIPLY);
					break;
				case sf::Keyboard::Left:
					keyEvent.setKey(Keyboard::LEFTARROW);
					break;
				case sf::Keyboard::Right:
					keyEvent.setKey(Keyboard::RIGHTARROW);
					break;
				case sf::Keyboard::Up:
					keyEvent.setKey(Keyboard::UPARROW);
					break;
				case sf::Keyboard::Down:
					keyEvent.setKey(Keyboard::DOWNARROW);
					break;
				case sf::Keyboard::F1:
					keyEvent.setKey(Keyboard::F1);
					break;
				case sf::Keyboard::F2:
					keyEvent.setKey(Keyboard::F2);
					break;
				case sf::Keyboard::F3:
					keyEvent.setKey(Keyboard::F3);
					break;
				case sf::Keyboard::F4:
					keyEvent.setKey(Keyboard::F4);
					break;
				case sf::Keyboard::F5:
					keyEvent.setKey(Keyboard::F5);
					break;
				case sf::Keyboard::F6:
					keyEvent.setKey(Keyboard::F6);
					break;
				case sf::Keyboard::F7:
					keyEvent.setKey(Keyboard::F7);
					break;
				case sf::Keyboard::F8:
					keyEvent.setKey(Keyboard::F8);
					break;
				case sf::Keyboard::F9:
					keyEvent.setKey(Keyboard::F9);
					break;
				case sf::Keyboard::F10:
					keyEvent.setKey(Keyboard::F10);
					break;
				case sf::Keyboard::F11:
					keyEvent.setKey(Keyboard::F11);
					break;
				case sf::Keyboard::F12:
					keyEvent.setKey(Keyboard::F12);
					break;
				case sf::Keyboard::Pause:
					keyEvent.setKey(Keyboard::PAUSE);
					break;
				default:
					break;
			}

			onEvent(&keyEvent);
		} else if (event.type == sf::Event::MouseMoved) {
			EventMouse mouseEvent;
			mouseEvent.setMouseAction(MOVED);
			mouseEvent.setMousePosition(df::pixelsToSpaces(Vector(event.mouseMove.x, event.mouseMove.y)));
			onEvent(&mouseEvent);
		} else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
			EventMouse mouseEvent;

			if (event.type == sf::Event::MouseButtonPressed)
				mouseEvent.setMouseAction(CLICKED);
			else if (event.type == sf::Event::MouseButtonReleased)
				mouseEvent.setMouseAction(PRESSED);

			if (event.mouseButton.button == sf::Mouse::Left)
				mouseEvent.setMouseButton(Mouse::LEFT);
			else if (event.mouseButton.button == sf::Mouse::Right)
				mouseEvent.setMouseButton(Mouse::RIGHT);
			else if (event.mouseButton.button == sf::Mouse::Middle)
				mouseEvent.setMouseButton(Mouse::MIDDLE);

			mouseEvent.setMousePosition(df::pixelsToSpaces(Vector(event.mouseButton.x, event.mouseButton.y)));
//			LM.writeLog(0, "pos: %i, %i", event.mouseButton.x, event.mouseButton.y);
			onEvent(&mouseEvent);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		EventKeyboard e(Keyboard::W, KEY_DOWN);
		onEvent(&e);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		EventKeyboard e(Keyboard::A, KEY_DOWN);
		onEvent(&e);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		EventKeyboard e(Keyboard::S, KEY_DOWN);
		onEvent(&e);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		EventKeyboard e(Keyboard::D, KEY_DOWN);
		onEvent(&e);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		EventMouse e(PRESSED, Mouse::LEFT,
		             df::pixelsToSpaces(Vector(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)));
}
