#include <cmath>
#include <string>
#include <sstream>
#include "Vector.h"

df::Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

df::Vector::Vector() {
	x = 0;
	y = 0;
}

void df::Vector::setX(float newX) {
	x = newX;
}

float df::Vector::getX() const {
	return x;
}

void df::Vector::setY(float newY) {
	y = newY;
}

float df::Vector::getY() const {
	return y;
}

void df::Vector::setXY(float newX, float newY) {
	x = newX;
	y = newY;
}

float df::Vector::getMagnitude() const {
	float magnitude = sqrt(x * x + y * y);
	return magnitude;
}

void df::Vector::normalize() {
	float magnitude = getMagnitude();
	if (magnitude != 0) {
		x = x / magnitude;
		y = y / magnitude;
	}
}

void df::Vector::scale(float scale) {
	x = x * scale;
	y = y * scale;
}

df::Vector df::Vector::operator+(const df::Vector &other) const {
	Vector v;
	v.x = x + other.x;
	v.y = y + other.y;
	return v;
}

df::Vector df::Vector::operator-(const df::Vector &other) const {
	Vector v;
	v.x = x - other.x;
	v.y = y - other.y;
	return v;
}

df::Vector df::Vector::operator*(const df::Vector &other) const {
	Vector v;
	v.x = x * other.x;
	v.y = y * other.y;
	return v;
}

df::Vector df::Vector::operator/(const df::Vector &other) const {
	Vector v;
	v.x = x / other.x;
	v.y = y / other.y;
	return v;
}

bool df::Vector::operator==(const df::Vector &other) const {
	return (x == other.x && y == other.y);
}

bool df::Vector::operator!=(const df::Vector &other) const {
	return (x != other.x || y != other.y);
}

df::Vector &df::Vector::operator+=(const df::Vector &other) {
	x += other.x;
	y += other.y;
	return *this;
}

bool df::Vector::operator!() const {
	return (x == 0 && y == 0);
}

std::string df::Vector::toString() const {
	std::stringstream ss;
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}
