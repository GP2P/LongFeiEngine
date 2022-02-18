//
// Explosion.cpp
//

// Engine includes.
#include "DisplayManager.h"
#include "EventStep.h"
#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"

// Game includes.
#include "Explosion.h"

Explosion::Explosion() {
	setType("Explosion");

	// Exit after about 6 steps.
	time_to_live = 6;

	// Doesn't collide
	setSolidness(df::SPECTRAL);

	// Need step event to countdown.
#ifdef DF_REGISTER_INTEREST
	registerInterest(df::STEP_EVENT);
#endif
}

// Handle event.
// Return 0 if ignored, else 1.
int Explosion::eventHandler(const df::Event *p_e) {

	if (p_e->getType() == df::STEP_EVENT) {
		step();
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}

// Count down until explosion finished.
void Explosion::step() {
	time_to_live--;
	if (time_to_live <= 0)
		WM.markForDelete(this);
}

int Explosion::draw() {
	DM.drawCh(getPosition(), '*', df::RED);

	if (time_to_live < 4) {
		df::Vector p1(getPosition().getX() - 1, getPosition().getY() - 1);
		df::Vector p2(getPosition().getX() + 1, getPosition().getY() - 1);
		df::Vector p3(getPosition().getX() - 1, getPosition().getY() + 1);
		df::Vector p4(getPosition().getX() + 1, getPosition().getY() + 1);
		DM.drawCh(p1, '\\', df::RED);
		DM.drawCh(p2, '/', df::RED);
		DM.drawCh(p3, '/', df::RED);
		DM.drawCh(p4, '\\', df::RED);
	}

	return 0;
}
