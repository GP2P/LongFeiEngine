#include "Object.h"
#include "WorldManager.h"

df::Object::Object() {
	static int count = 0;
	count++;
	id = count;
	type = "Object";
	position = Vector();
	altitude = WM.MAX_ALTITUDE / 2;
	direction = Vector();
	speed = 0;
	WM.insertObject(this);
}

df::Object::~Object() {
	WM.removeObject(this);
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

int df::Object::draw() {
	return 0;
}

int df::Object::getAltitude() const {
	return altitude;
}

int df::Object::setAltitude(int altitude) {
	if (altitude < 0 || altitude > WM.MAX_ALTITUDE)
		return -1;
	else
		this->altitude = altitude;
	return 0;
}

float df::Object::getSpeed() const {
	return speed;
}

void df::Object::setSpeed(float speed) {
	this->speed = speed;
}

df::Vector df::Object::getDirection() const {
	return direction;
}

void df::Object::setDirection(df::Vector direction) {
	this->direction = direction;
}

df::Vector df::Object::getVelocity() const {
	return {direction.getX() * speed, direction.getY() * speed};
}

void df::Object::setVelocity(df::Vector velocity) {
	speed = velocity.getMagnitude();
	if (speed == 0)
		direction = Vector();
	else
		direction = {velocity.getX() / speed, velocity.getY() / speed};
}

df::Vector df::Object::predictPosition() {
	return position + getVelocity();
}

bool df::Object::isSolid() const {
	return solidness == HARD || solidness == SOFT;
}

void df::Object::setSolidness(df::Solidness solidness) {
	this->solidness = solidness;
}

df::Solidness df::Object::getSolidness() const {
	return solidness;
}
