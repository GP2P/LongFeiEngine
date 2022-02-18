//
// GameOver.h
//

#include "Object.h"

class GameOver : public df::Object {

private:
	int time_to_live;

	void step();

public:
	GameOver();

	int eventHandler(const df::Event *p_e);

	int draw();
};
