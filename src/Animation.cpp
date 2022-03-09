#include "Animation.h"

df::Animation::Animation() {
	p_sprite = nullptr;
	name = "";
	index = 0;
	slowdownCounter = 0;
}

void df::Animation::setSprite(df::Sprite *p_sprite) {
	this->p_sprite = p_sprite;
}

df::Sprite *df::Animation::getSprite() const {
	return p_sprite;
}

void df::Animation::setName(std::string name) {
	this->name = name;
}

std::string df::Animation::getName() const {
	return name;
}

void df::Animation::setIndex(int index) {
	this->index = index;
}

int df::Animation::getIndex() const {
	return index;
}

void df::Animation::setSlowdownCounter(int slowdownCounter) {
	this->slowdownCounter = slowdownCounter;
}

int df::Animation::getSlowdownCounter() const {
	return slowdownCounter;
}

df::Box df::Animation::getBox() const {
	if (!p_sprite) {
		Box box(Vector(-0.5, -0.5), 1, 1);
		return box;
	}

	Vector corner(-1 * p_sprite->getWidth() / 2, -1 * p_sprite->getHeight() / 2);
	Box box(corner, p_sprite->getWidth(), p_sprite->getHeight());
	return box;
}

int df::Animation::draw(df::Vector position) {
	if (p_sprite == nullptr)
		return -1;

	p_sprite->draw(index, position);

	if (slowdownCounter == -1)
		return 0;

	if (slowdownCounter + 1 >= p_sprite->getSlowdown()) {
		slowdownCounter = 0;
		index++;
		if (index >= p_sprite->getFrameCount())
			index = 0;
	}
	slowdownCounter++;
	return 0;
}
