#ifndef DF_GAMEMANAGER_H
#define DF_GAMEMANAGER_H

#include "Manager.h"

#define GM df::GameManager::getInstance()

namespace df {

	const std::string CONFIG_FILENAME = "lf-config.txt";

	// ms per frame
	const int FRAME_TIME_DEFAULT = 33;

	class GameManager : public Manager {

	private:

		GameManager();

		GameManager(GameManager const &);

		void operator=(GameManager const &);

		bool game_over;
		int frame_time;
		int step_count;

	public:

		static GameManager &getInstance();

		// startup all GameManager services
		// return 0 if ok, else -1
		int startUp(int frameTimeMS = FRAME_TIME_DEFAULT);

		// shut down GameManager services
		void shutDown() override;

		void run();

		void setGameOver(bool gameOver = true);

		bool getGameOver() const;

		int getFrameTime() const;

		int getStepCount() const;
	};
}

#endif //DF_GAMEMANAGER_H
