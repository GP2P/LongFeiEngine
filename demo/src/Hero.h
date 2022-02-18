// Hero.h
//

#include "EventKeyboard.h"
#include "EventMouse.h"
#include "Object.h"
#include "Reticle.h"

#define HERO_CHAR '>'

class Hero : public df::Object {

private:
	Reticle *p_reticle;
	int fire_slowdown;
	int fire_countdown;
	int nuke_count;

	void mouse(const df::EventMouse *p_mouse_event);

	void kbd(const df::EventKeyboard *keyboard_event);

	void move(int dy);

	void fire(df::Vector target);

	void step();

	void nuke();

public:
	Hero();

	~Hero();

	int eventHandler(const df::Event *p_e);

	int draw();
};
