#ifndef DF_INPUTMANAGER_H
#define DF_INPUTMANAGER_H

#include "Manager.h"

#define IM df::InputManager::getInstance()

namespace df {
	class InputManager : public Manager {

	private:
		InputManager();

		InputManager(const InputManager &);

		void operator=(const InputManager &);

	public:
		static InputManager &getInstance();

//		bool isValid(std::string eventType) const override;

		// get window ready to capture input
		// return 0 if ok, else -1
		int startUp() override;

		// revert to normal window mode
		void shutDown() override;

		// get input from keyboard and mouse
		// pass event along to all Objects
		void getInput();
	};
}

#endif //DF_INPUTMANAGER_H
