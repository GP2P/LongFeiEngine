#include "EventView.h"

df::EventView::EventView() {
	setType(VIEW_EVENT);
	tag = VIEW_EVENT;
	value = 0;
	delta = false;
}

df::EventView::EventView(std::string tag, int value, bool delta) {
	setType(VIEW_EVENT);
	this->tag = tag;
	this->value = value;
	this->delta = delta;
}

void df::EventView::setTag(std::string tag) {
	this->tag = tag;
}

std::string df::EventView::getTag() const {
	return tag;
}

void df::EventView::setValue(int value) {
	this->value = value;
}

int df::EventView::getValue() const {
	return value;
}

void df::EventView::setDelta(bool delta) {
	this->delta = delta;
}

bool df::EventView::getDelta() const {
	return delta;
}
