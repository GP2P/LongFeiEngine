#include "EventCollision.h"
#include "Vector.h"
#include "Object.h"

df::EventCollision::EventCollision() {
	position = Vector();
	p_object1 = nullptr;
	p_object2 = nullptr;
	setType(COLLISION_EVENT);
}

df::EventCollision::EventCollision(Object *p_object1, Object *p_object2, Vector position) {
	this->position = position;
	this->p_object1 = p_object1;
	this->p_object2 = p_object2;
	setType(COLLISION_EVENT);
}

void df::EventCollision::setObject1(Object *p_object1) {
	this->p_object1 = p_object1;
}

df::Object *df::EventCollision::getObject1() const {
	return p_object1;
}

void df::EventCollision::setObject2(Object *p_object2) {
	this->p_object2 = p_object2;
}

df::Object *df::EventCollision::getObject2() const {
	return p_object2;
}

void df::EventCollision::setPosition(df::Vector position) {
	this->position = position;
}

df::Vector df::EventCollision::getPosition() const {
	return position;
}
