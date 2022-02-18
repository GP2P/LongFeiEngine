//
// Star.cpp
//

#include <stdlib.h>        // for rand()

// Engine includes.
#include "DisplayManager.h"
#include "EventOut.h"
#include "LogManager.h"

// Game includes.
#include "Star.h"

Star::Star() {
	setType("Star");
	setSolidness(df::SPECTRAL);
	setVelocity(df::Vector((float) -1.0 / (rand() % 9 + 2), 0));
	setAltitude(0);    // Make them in the background.
	df::Vector p((float) (rand() % (int) DM.getHorizontal()),
	             (float) (rand() % (int) DM.getVertical()));
	setPosition(p);
}

int Star::draw() {
	DM.drawCh(getPosition(), STAR_CHAR, df::WHITE);
	return 0;
}

// Handle event.
// Return 0 if ignored, else 1.
int Star::eventHandler(const df::Event *p_e) {

	if (p_e->getType() == df::OUT_EVENT) {
		out();
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}

// If Star moved off screen, move back to far right.
void Star::out() {
	df::Vector pos((float) (DM.getHorizontal() + rand() % 20),
	               (float) (rand() % DM.getVertical()));
	setPosition(pos);
	setVelocity(df::Vector((float) -1.0 / (rand() % 9 + 2), 0));
}
