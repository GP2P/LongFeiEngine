#include "Object.h"
#include "GameManager.h"
#include "WorldManager.h"

df::Object::Object() {
	static int count = 0;
	count++;
	id = count;
	type = "Object";
	position = Vector();
	WM.insertObject(this);
}

df::Object::~Object() {
	WM.markForDelete(this);
}

void df::Object::setId(int id) {
	this->id = id;
}

int df::Object::getId() const {
	return id;
}

void df::Object::setType(std::string type) {
	this->type = type;
}

std::string df::Object::getType() const {
	return type;
}

void df::Object::setPosition(df::Vector position) {
	this->position = position;
}

df::Vector df::Object::getPosition() const {
	return position;
}

int df::Object::eventHandler(const df::Event *p_event) {
	return 0;
}
