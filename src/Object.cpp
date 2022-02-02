#include "Object.h"

df::Object::Object() {
	static int count = 0;
	count++;
	id = count;
	type = "Object";
	position = Vector();
}

df::Object::~Object() {

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
