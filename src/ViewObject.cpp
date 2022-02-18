#include <sstream>
#include "ViewObject.h"
#include "Color.h"
#include "Object.h"
#include "WorldManager.h"
#include "utility.h"
#include "DisplayManager.h"
#include "EventView.h"

df::ViewObject::ViewObject() {
	setSolidness(SPECTRAL);
	setAltitude(WM.MAX_ALTITUDE);
	setType("ViewObject");
	viewString = "";
	value = 0;
	drawValue = false;
	haveBorder = true;
	color = COLOR_DEFAULT;
	location = TOP_CENTER;
}

int df::ViewObject::draw() {
	std::string str;

	if (haveBorder) {
		if (drawValue)
			str = " " + viewString + " " + toString(value) + " ";
		else
			str = " " + viewString + " ";
		std::stringstream border;
		for (int i = 0; i < str.length(); i++) {
			border << '-';
		}
		DM.drawString(viewToWorld(getPosition() + Vector(0, 1)), border.str(), CENTER_JUSTIFIED, color);
		DM.drawString(viewToWorld(getPosition() - Vector(0, 1)), border.str(), CENTER_JUSTIFIED, color);
	} else if (drawValue)
		str = viewString + " " + toString(value);
	else
		str = viewString;

	DM.drawString(viewToWorld(getPosition()), str, CENTER_JUSTIFIED, color);
	return 0;
}

int df::ViewObject::eventHandler(const df::Event *p_e) {
	if (p_e->getType() == VIEW_EVENT) {
		auto *p_ev = const_cast<EventView *>(static_cast <const EventView *>(p_e));
//		EventView *p_ev = static_cast <const EventView *>(p_e); //TODO

		if (p_ev->getTag() == viewString) {
			if (p_ev->getDelta())
				setValue(value + p_ev->getValue());
			else
				setValue(p_ev->getValue());
			return 1;
		}
	}
	return -1;
}

void df::ViewObject::setLocation(df::ViewObjectLocation location) {
	Vector position = Vector();

	switch (location) {
		case TOP_LEFT:
			position.setX(WM.getViewBoundary().getWidth() * 1 / 6);
			if (haveBorder)
				position.setY(1);
			break;
		case TOP_CENTER:
			position.setX(WM.getViewBoundary().getWidth() * 1 / 2);
			if (haveBorder)
				position.setY(1);
			break;
		case TOP_RIGHT:
			position.setX(WM.getViewBoundary().getWidth() * 5 / 6);
			if (haveBorder)
				position.setY(1);
			break;
		case CENTER_LEFT:
			position.setXY(WM.getViewBoundary().getWidth() * 1 / 6, WM.getViewBoundary().getHeight() * 1 / 2);
			break;
		case CENTER_CENTER:
			position.setXY(WM.getViewBoundary().getWidth() * 1 / 2, WM.getViewBoundary().getHeight() * 1 / 2);
			break;
		case CENTER_RIGHT:
			position.setXY(WM.getViewBoundary().getWidth() * 5 / 6, WM.getViewBoundary().getHeight() * 1 / 2);
			break;
		case BOTTOM_LEFT:
			position.setX(WM.getViewBoundary().getWidth() * 1 / 6);
			if (haveBorder)
				position.setY(WM.getViewBoundary().getHeight() - 1);
			else
				position.setY(WM.getViewBoundary().getHeight());
			break;
		case BOTTOM_CENTER:
			position.setX(WM.getViewBoundary().getWidth() * 1 / 2);
			if (haveBorder)
				position.setY(WM.getViewBoundary().getHeight() - 1);
			else
				position.setY(WM.getViewBoundary().getHeight());
			break;
		case BOTTOM_RIGHT:
			position.setX(WM.getViewBoundary().getWidth() * 5 / 6);
			if (haveBorder)
				position.setY(WM.getViewBoundary().getHeight() - 1);
			else
				position.setY(WM.getViewBoundary().getHeight());
			break;
		default:
			return;
	}

	this->location = location;
	setPosition(position);
}

df::ViewObjectLocation df::ViewObject::getLocation() const {
	return location;
}

void df::ViewObject::setDrawValue(bool drawValue) {
	this->drawValue = drawValue;
}

bool df::ViewObject::getDrawValue() const {
	return drawValue;
}

void df::ViewObject::setValue(int value) {
	this->value = value;
}

int df::ViewObject::getValue() const {
	return value;
}

void df::ViewObject::setBorder(bool haveBorder) {
	this->haveBorder = haveBorder;
	setLocation(location);
}

bool df::ViewObject::getBorder() const {
	return haveBorder;
}

void df::ViewObject::setColor(df::Color color) {
	this->color = color;
}

df::Color df::ViewObject::getColor() const {
	return color;
}

void df::ViewObject::setViewString(std::string viewString) {
	this->viewString = viewString;
}

std::string df::ViewObject::getViewString() const {
	return viewString;
}
