#include "Sprite.h"

df::Sprite::Sprite() {
	width = 0;
	height = 0;
	maxFrameCount = 0;
	frameCount = 0;
	color = COLOR_DEFAULT;
	slowdown = 1;
	frames = nullptr;
	label = "";
}

df::Sprite::~Sprite() {
	if (frames != nullptr) {
		delete[] frames;
		frames = nullptr;
	}
}

df::Sprite::Sprite(int maxFrameCount) {
	width = 0;
	height = 0;
	frameCount = 0;
	color = COLOR_DEFAULT;
	slowdown = 1;
	label = "";
	this->maxFrameCount = maxFrameCount;
	frames = new Frame[maxFrameCount];
}

void df::Sprite::setWidth(int width) {
	this->width = width;
}

int df::Sprite::getWidth() const {
	return width;
}

void df::Sprite::setHeight(int height) {
	this->height = height;
}

int df::Sprite::getHeight() const {
	return height;
}

int df::Sprite::getFrameCount() const {
	return frameCount;
}

void df::Sprite::setFrameCount(int frameCount) {
	this->frameCount = frameCount;
}

df::Color df::Sprite::getColor() const {
	return color;
}

void df::Sprite::setColor(df::Color color) {
	this->color = color;
}

df::Frame *df::Sprite::getFrame(int index) const {
	if (index < 0 || index >= maxFrameCount) {
		Frame *empty = new Frame(0, 0, "");
		return empty;
	}
	return &frames[index];
}

int df::Sprite::getSlowdown() const {
	return slowdown;
}

void df::Sprite::setSlowdown(int slowdown) {
	this->slowdown = slowdown;
}

std::string df::Sprite::getLabel() const {
	return label;
}

void df::Sprite::setLabel(const std::string label) {
	this->label = label;
}

int df::Sprite::addFrame(df::Frame p_frame) {
	if (frameCount < maxFrameCount) {
		frames[frameCount] = p_frame;
		frameCount++;
		return 0;
	}
	return -1;
}

int df::Sprite::draw(int frameNumber, df::Vector position) const {
	if (frameNumber < 0 || frameNumber >= frameCount) {
		return -1;
	}
	frames[frameNumber].draw(position, color);
	return 0;
}
