#include <ctime>
#include <cstdio>
#include <sstream>
#include "utility.h"
#include "WorldManager.h"

char *df::getTimeString() {
	static char time_str[30];

	time_t now;
	time(&now);
	struct tm *p_time = localtime(&now);

	sprintf(time_str, "%02d:%02d:%02d",
	        p_time->tm_hour,
	        p_time->tm_min,
	        p_time->tm_sec);
	return time_str;
}

bool df::positionsIntersect(df::Vector p1, df::Vector p2) {
	return (abs(p1.getX() - p2.getX()) <= 1) && (abs(p1.getY() - p2.getY()) <= 1);
}

bool df::boxIntersectsBox(Box b1, Box b2) {
	return (b1.getCorner().getX() <= b2.getCorner().getX() + b2.getWidth() &&
	        b1.getCorner().getX() + b1.getWidth() >= b2.getCorner().getX() &&
	        b1.getCorner().getY() <= b2.getCorner().getY() + b2.getHeight() &&
	        b1.getCorner().getY() + b1.getHeight() >= b2.getCorner().getY());
}

df::Box df::getWorldBox(const df::Object *p_o) {
	return getWorldBox(p_o, p_o->getPosition());
}

df::Box df::getWorldBox(const df::Object *p_o, df::Vector position) {
	df::Box oriBox = p_o->getBox();
	df::Vector oriCorner = oriBox.getCorner();
	return {df::Vector(oriCorner.getX() + position.getX(), oriCorner.getY() + position.getY()),
	        oriBox.getWidth(), oriBox.getHeight()};
}

df::Vector df::worldToView(Vector worldPosition) {
	return {worldPosition.getX() - WM.getViewBoundary().getCorner().getX(),
	        worldPosition.getY() - WM.getViewBoundary().getCorner().getY()};
}

df::Vector df::viewToWorld(Vector viewPosition) {
	return {viewPosition.getX() + WM.getViewBoundary().getCorner().getX(),
	        viewPosition.getY() + WM.getViewBoundary().getCorner().getY()};
}

std::string df::toString(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}
