//
// Saucer.cpp
//

// Uncomment if Dragonfly uses STL instead of ObjectList.
#define USE_STL

#include <stdlib.h>        // for rand()

#ifdef USE_STL

#include <vector>

#endif

// Engine includes.
#include "DisplayManager.h"
#include "EventCollision.h"
#include "EventNuke.h"
#include "EventOut.h"
#include "LogManager.h"
#include "WorldManager.h"

// Game includes.
#include "Explosion.h"
#include "Saucer.h"
#include "ObjectListIterator.h"

Saucer::Saucer() {

	// Set object type.
	setType("Saucer");

	// Set speed in horizontal direction.
	setVelocity(df::Vector(-0.25, 0)); // 1 space left every 4 frames

	moveToStart();

	// Register interest in "nuke" event.
#ifdef DF_REGISTER_INTEREST
	registerInterest(NUKE_EVENT);
#endif
}

// Handle event.
// Return 0 if ignored, else 1.
int Saucer::eventHandler(const df::Event *p_e) {

	if (p_e->getType() == df::OUT_EVENT) {
		out();
		return 1;
	}

	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision *p_collision_event = dynamic_cast <const df::EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

	if (p_e->getType() == NUKE_EVENT) {

		// Create explosion.
		Explosion *p_explosion = new Explosion;
		p_explosion->setPosition(this->getPosition());

		// Delete self.
		WM.markForDelete(this);

		// Saucers appear stay around perpetually
		new Saucer;
	}

	// If get here, have ignored this event.
	return 0;
}

// If moved off left edge, move back to far right.
void Saucer::out() {

	// If haven't moved off left edge, then nothing to do.
	if (getPosition().getX() >= 0)
		return;

	// Otherwise, move back to far right.
	moveToStart();

	// Spawn new Saucer to make the game get harder.
	new Saucer;

}

// If saucer and player collide, mark both for deletion.
void Saucer::hit(const df::EventCollision *p_c) {

	// If Saucer on Saucer, ignore.
	if ((p_c->getObject1()->getType() == "Saucer") &&
	    (p_c->getObject2()->getType() == "Saucer"))
		return;

	// If Bullet ...
	if ((p_c->getObject1()->getType() == "Bullet") ||
	    (p_c->getObject2()->getType() == "Bullet")) {

		// Create an explosion.
		Explosion *p_explosion = new Explosion;
		p_explosion->setPosition(this->getPosition());

		// Saucers appear stay around perpetually.
		new Saucer;
	}

	// If Hero, mark both objects for destruction.
	if (((p_c->getObject1()->getType()) == "Hero") ||
	    ((p_c->getObject2()->getType()) == "Hero")) {
		WM.markForDelete(p_c->getObject1());
		WM.markForDelete(p_c->getObject2());
	}

}

// Move saucer to starting location on right side of screen.
void Saucer::moveToStart() {
	df::Vector temp_pos;

	// Get world boundaries.
	int world_horiz = (int) DM.getHorizontal();
	int world_vert = (int) DM.getVertical();

	// x is off right side of screen.
	temp_pos.setX(world_horiz + rand() % world_horiz + 3.0f);

	// y is in vertical range.
	temp_pos.setY(rand() % (world_vert) + 0.0f);

	// If collision, move right slightly until empty space.
#ifdef USE_STL
	df::ObjectList collision_list = WM.getCollisions(this, temp_pos);
	df::ObjectListIterator i(&collision_list);
	while (!i.isDone()) {
		temp_pos.setX(temp_pos.getX() + 1.0f);
		collision_list = WM.getCollisions(this, temp_pos);
		i.next();
	}
#else
	df::ObjectList collision_list = WM.getCollisions(this, temp_pos);
	while (!collision_list.isEmpty()) {
	  temp_pos.setX(temp_pos.getX()+1.0f);
	  collision_list = WM.getCollisions(this, temp_pos);
	}
#endif

//  LM.writeLog(1, "Saucer: moveToStart: %f, %f", temp_pos.getX(), temp_pos.getY());
	WM.moveObject(this, temp_pos);
}

int Saucer::draw() {
	DM.drawCh(getPosition(), SAUCER_CHAR, df::GREEN);
	return 0;
}
