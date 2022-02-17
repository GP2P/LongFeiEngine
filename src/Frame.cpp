#include "Frame.h"
#include "DisplayManager.h"

df::Frame::Frame() {
	width = 0;
	height = 0;
	frameContent = "";
}

df::Frame::Frame(int width, int height, std::string frameContent) {
	this->width = width;
	this->height = height;
	this->frameContent = frameContent;
}

void df::Frame::setWidth(int width) {
	this->width = width;
}

int df::Frame::getWidth() const {
	return width;
}

void df::Frame::setHeight(int height) {
	this->height = height;
}

int df::Frame::getHeight() const {
	return height;
}

void df::Frame::setFrameContent(std::string frameContent) {
	this->frameContent = frameContent;
}

std::string df::Frame::getFrameContent() const {
	return frameContent;
}

int df::Frame::draw(df::Vector position, df::Color color) const {
	if (frameContent.empty())
		return -1;

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			if (frameContent[y * width + x] != ' ')
				DM.drawCh(position + df::Vector(x - width / 2, y - height / 2), frameContent[y * width + x], color);
}

void df::Frame::setString(std::string frameContent) {
	setFrameContent(frameContent);
}

std::string df::Frame::getString() const {
	return getFrameContent();
}
