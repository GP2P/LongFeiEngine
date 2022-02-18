//
// Bullet.h
//

#include "EventCollision.h"
#include "Object.h"

#define BULLET_CHAR '-'

class Bullet : public df::Object {

private:
	void out();

	void hit(const df::EventCollision *p_c);

public:
	Bullet(df::Vector hero_pos);

	int eventHandler(const df::Event *p_e);

	int draw();
};
