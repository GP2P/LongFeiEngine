#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "WorldManager.h"

df::GameManager::GameManager() {
	game_over = false;
	frame_time = FRAME_TIME_DEFAULT;
	step_count = 0;
	setType("GameManager");
}

df::GameManager &df::GameManager::getInstance() {
	static GameManager instance;
	return instance;
}

int df::GameManager::startUp(int frameTimeMS) {
	if (GM.isStarted())
		return 0;
	frame_time = frameTimeMS;
	if (LM.getInstance().startUp() == -1) {
		return -1;
	} else if (WM.getInstance().startUp() == -1) {
		return -1;
	} else
		return Manager::startUp();
}

void df::GameManager::shutDown() {
	setGameOver(true);
	LM.shutDown();
	return Manager::shutDown();
}

void df::GameManager::run() {
	Clock clock;
	long int adjust_time = 0;
	while (!game_over) {
		clock.delta();
		// do something
		step_count++;
		long int time_elapsed = clock.split();
		long int intended_sleep_time = frame_time * 1000 - time_elapsed - adjust_time;
//		LM.writeLog(2, "run(): time elapsed %ld microsecond", time_elapsed);
		if (intended_sleep_time > 0) {
			// sleep
			struct timespec sleep_time;
			sleep_time.tv_sec = 0;
			sleep_time.tv_nsec = intended_sleep_time * 1000;
//			LM.writeLog(2, "GameManager::run(): intended sleep time: %ld ", intended_sleep_time);
			nanosleep(&sleep_time, NULL);
		}
		long int actual_sleep_time = clock.split();
		adjust_time = actual_sleep_time - intended_sleep_time;
		if (adjust_time < 0)
			adjust_time = 0;
	}
}

void df::GameManager::setGameOver(bool gameOver) {
	game_over = gameOver;
}

bool df::GameManager::getGameOver() const {
	return game_over;
}

int df::GameManager::getFrameTime() const {
	return frame_time;
}

int df::GameManager::getStepCount() const {
	return step_count;
}
