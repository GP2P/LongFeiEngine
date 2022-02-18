#include "Box.h"
#include "DisplayManager.h"
#include "utility.h"

df::Box::Box() {
	corner = Vector();
	width = 0;
	height = 0;
}

df::Box::Box(df::Vector corner, float width, float height) {
	this->corner = corner;
	this->width = width;
	this->height = height;
}

void df::Box::setCorner(df::Vector corner) {
	this->corner = corner;
}

df::Vector df::Box::getCorner() const {
	return corner;
}

void df::Box::setWidth(float width) {
	this->width = width;
}

float df::Box::getWidth() const {
	return width;
}

void df::Box::setHeight(float height) {
	this->height = height;
}

float df::Box::getHeight() const {
	return height;
}

std::string df::Box::toString() const {
	std::string output = "Box: ";
	output += corner.toString();
	output += " ";
	output += std::to_string(width);
	output += " ";
	output += std::to_string(height);
	return output;
}

bool df::Box::operator==(const df::Box &rhs) const {
	return (corner == rhs.corner && width == rhs.width && height == rhs.height);
}

bool df::Box::operator!=(const df::Box &rhs) const {
	return !(*this == rhs);
}

void df::Box::draw() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			df::Vector temp = corner + Vector(i, j);
			DM.drawCh(temp, '*', df::RED);
		}
	}
}

void df::Box::draw(Vector position) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			df::Vector temp = corner + Vector(i, j);
			DM.drawCh(temp + position, '*', df::RED);
		}
	}
}
