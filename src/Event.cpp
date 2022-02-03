#include "Event.h"

df::Event::Event() {
	type = UNDEFINED_EVENT;
}

df::Event::~Event() {

}

void df::Event::setType(std::string type) {
	this->type = type;
}

std::string df::Event::getType() const {
	return type;
}
