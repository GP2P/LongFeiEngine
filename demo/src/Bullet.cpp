//
// Bullet.cpp
//

// Engine includes.
#include "DisplayManager.h"
#include "EventOut.h"
#include "LogManager.h"
#include "WorldManager.h"

// Game includes.
#include "Bullet.h"
#include "Saucer.h"

Bullet::Bullet(df::Vector hero_pos) {

	// Set object properties.
	setType("Bullet");
	setVelocity(df::Vector(1, 0)); // Move 1 space right every game loop.

	// Set starting location, based on hero's position passed in.
	df::Vector p(hero_pos.getX() + 3, hero_pos.getY());
	setPosition(p);
}

// Handle event.
// Return 0 if ignored, else 1.
int Bullet::eventHandler(const df::Event *p_e) {

	if (p_e->getType() == df::OUT_EVENT) {
		out();
		return 1;
	}

	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision *p_collision_event = dynamic_cast <const df::EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

	// If get here, have ignored this event.
	return 0;
}

// If bullet moves outside world, mark self for deletion.
void Bullet::out() {
	WM.markForDelete(this);
}

// If bullet hits Saucer, mark Saucer and bullet for deletion.
void Bullet::hit(const df::EventCollision *p_c) {
	WM.markForDelete(p_c->getObject1());
	WM.markForDelete(p_c->getObject2());
}

int Bullet::draw() {
	DM.drawCh(getPosition(), BULLET_CHAR, df::BLUE);
	return 0;
}
