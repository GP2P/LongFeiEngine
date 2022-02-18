#include "Music.h"

df::Music::Music() {
}

int df::Music::loadMusic(std::string filename) {
	return music.openFromFile(filename) ? 0 : -1;
}

void df::Music::setLabel(std::string label) {
	this->label = label;
}

std::string df::Music::getLabel() const {
	return label;
}

void df::Music::play(bool loop) {
	music.setLoop(loop);
	music.play();
}

void df::Music::stop() {
	music.stop();
}

void df::Music::pause() {
	music.pause();
}

sf::Music *df::Music::getMusic() {
	return &music;
}
