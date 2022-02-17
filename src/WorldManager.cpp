#include "WorldManager.h"
#include "LogManager.h"
#include "ObjectListIterator.h"
#include "utility.h"
#include "EventCollision.h"
#include "DisplayManager.h"
#include "EventOut.h"

df::WorldManager::WorldManager() {
	update_list.clear();
	delete_list.clear();
	setType("WorldManager");
}

df::WorldManager &df::WorldManager::getInstance() {
	static WorldManager instance;
	return instance;
}

int df::WorldManager::startUp() {
	if (WM.isStarted())
		return 0;
	update_list.clear(); // clear the update list
	delete_list.clear(); // clear the update list
	LM.writeLog(1, "WorldManager::startUp(): WorldManager started successfully");
	return Manager::startUp();
}

void df::WorldManager::shutDown() {
	ObjectList ol = update_list;
	auto oli = ObjectListIterator(&ol);
	while (!oli.isDone()) {
		delete oli.currentObject();
		oli.next();
	}

	update_list.clear(); // clear the update list
	delete_list.clear(); // clear the delete list
	Manager::shutDown();
}

int df::WorldManager::insertObject(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(4, "WorldManager::insertObject(): NULL object");
		return -1;
	} else if (update_list.insert(p_o) == -1) {
		LM.writeLog(4, "WorldManager::insertObject(): object not inserted");
		return -1;
	} else
		return 0;
}

int df::WorldManager::removeObject(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(4, "WorldManager::removeObject(): NULL object");
		return -1;
	} else if (update_list.remove(p_o) == -1) {
		LM.writeLog(4, "WorldManager::removeObject(): object ID: %i not removed", p_o->getId());
		return -1;
	} else
		return 0;
}

df::ObjectList df::WorldManager::getAllObjects() const {
	return update_list;
}

df::ObjectList df::WorldManager::objectsOfType(std::string type) const {
	ObjectList result = ObjectList();
	auto oli = ObjectListIterator(&update_list);
	while (!oli.isDone()) {
		if (oli.currentObject()->getType() == type)
			result.insert(oli.currentObject());
		oli.next();
	}
	return result;
}

void df::WorldManager::update() {
	// update all objects in the update list
	auto oli = ObjectListIterator(&update_list);
	while (!oli.isDone()) {
		Vector newPos = oli.currentObject()->predictPosition();
		if (newPos != oli.currentObject()->getPosition())
			moveObject(oli.currentObject(), newPos);
		oli.next();
	}

	// delete all objects in the delete list
	auto dli = ObjectListIterator(&delete_list);
	while (!dli.isDone()) {
		try {
			delete dli.currentObject();
		} catch (std::exception &e) {
			LM.writeLog(1, "WorldManager::update(): %s", e.what());
		}
		dli.next();
	}
	delete_list.clear();
}

void df::WorldManager::draw() {
	auto oli = ObjectListIterator(&update_list);
	for (int alt = 0; alt <= WM.MAX_ALTITUDE; alt++) {
		while (!oli.isDone()) {
			if (oli.currentObject()->getAltitude() == alt)
				if (boxIntersectsBox(getWorldBox(oli.currentObject()), viewBoundary))
					oli.currentObject()->draw();
			oli.next();
		}
		oli.first();
	}
}

int df::WorldManager::markForDelete(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(4, "WorldManager::markForDelete(): NULL object");
		return -1;
	} else {
		ObjectListIterator dli = ObjectListIterator(&delete_list);
		while (!dli.isDone()) {
			if (dli.currentObject() == p_o) {
				LM.writeLog(2, "WorldManager::markForDelete(): object ID: %i already marked for deletion",
				            p_o->getId());
				return -1;
			} else
				dli.next();
		}
	}
	if (delete_list.insert(p_o) == -1) {
		LM.writeLog(4, "WorldManager::markForDelete(): object not marked");
		return -1;
	} else
		return 0;
}

df::ObjectList df::WorldManager::getCollisions(df::Object *p_o, df::Vector position) const {
	ObjectList result = ObjectList();
	auto oli = ObjectListIterator(&update_list);
	while (!oli.isDone()) {
		if (oli.currentObject()->isSolid())
			if (oli.currentObject() != p_o)
				if (boxIntersectsBox(getWorldBox(p_o, position), getWorldBox(oli.currentObject())))
					result.insert(oli.currentObject());
		oli.next();
	}
	return result;
}

int df::WorldManager::moveObject(df::Object *p_Object, df::Vector newPosition) {

	// test for collisions
	if (p_Object->isSolid()) {
		auto ol = getCollisions(p_Object, newPosition);
		if (!ol.isEmpty()) {
			bool canMove = true;
			auto oli = ObjectListIterator(&ol);
			while (!oli.isDone()) {
				Object *p_O2 = oli.currentObject();
				EventCollision ec(p_Object, p_O2, newPosition);
				p_Object->eventHandler(&ec);
				p_O2->eventHandler(&ec);
				if (p_Object->getSolidness() == p_O2->getSolidness() == HARD)
					canMove = false;
				oli.next();
			}

			if (!canMove) {
				LM.writeLog(4, "WorldManager::moveObject(): object ID: %i not moved", p_Object->getId());
				return -1;
			}
		}
	}

	// move object
	Box originalBox = getWorldBox(p_Object);
	p_Object->setPosition(newPosition);
	Box newBox = getWorldBox(p_Object);

	// adjust view boundary if following
	if (p_focus_object == p_Object)
		setViewCenter(p_Object->getPosition());

	// check and send out of bounds event
	if (boxIntersectsBox(originalBox, worldBoundary) && !boxIntersectsBox(newBox, worldBoundary)) {
		EventOut eo;
		p_Object->eventHandler(&eo);
	}

	return 0;
}

const df::Box &df::WorldManager::getWorldBoundary() const {
	return worldBoundary;
}

void df::WorldManager::setWorldBoundary(const df::Box &worldBoundary) {
	this->worldBoundary = worldBoundary;
}

const df::Box &df::WorldManager::getViewBoundary() const {
	return viewBoundary;
}

void df::WorldManager::setViewBoundary(const df::Box &viewBoundary) {
	this->viewBoundary = viewBoundary;
}

void df::WorldManager::setViewCenter(df::Vector newCenter) {
	float x = newCenter.getX() - getViewBoundary().getWidth() / 2;
	if (x + getViewBoundary().getWidth() > worldBoundary.getWidth())
		x = worldBoundary.getWidth() - getViewBoundary().getWidth();
	if (x < 0)
		x = 0;

	float y = newCenter.getY() - getViewBoundary().getHeight() / 2;
	if (y + getViewBoundary().getHeight() > worldBoundary.getHeight())
		y = worldBoundary.getHeight() - getViewBoundary().getHeight();
	if (y < 0)
		y = 0;

	viewBoundary.setCorner(Vector(x, y));
}

int df::WorldManager::setViewFocus(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(2, "WorldManager::setViewFocus(): NULL object");
		p_focus_object = nullptr;
		return 0;
	}

	ObjectListIterator oli = ObjectListIterator(&update_list);
	while (!oli.isDone()) {
		if (oli.currentObject() == p_o) {
			p_focus_object = p_o;
			setViewCenter(p_focus_object->getPosition());
			return 0;
		}
		oli.next();
	}

	return -1;
}
