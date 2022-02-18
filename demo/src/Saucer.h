//
// Saucer.h
//

#include "EventCollision.h"
#include "Object.h"

#define SAUCER_CHAR 'O'

class Saucer : public df::Object {

private:
	void moveToStart();

	void out();

	void hit(const df::EventCollision *p_c);

public:
	Saucer();

	int eventHandler(const df::Event *p_e);

	int draw();
};
