#include "Sound.h"

df::Sound::Sound() = default;

int df::Sound::loadSound(std::string filename) {
	if (!soundBuffer.loadFromFile(filename))
		return -1;
	sound.setBuffer(soundBuffer);
	return 0;
}

void df::Sound::setLabel(std::string label) {
	this->label = label;
}

std::string df::Sound::getLabel() const {
	return label;
}

void df::Sound::play(bool loop) {
	sound.setLoop(loop);
	sound.play();
}

void df::Sound::stop() {
	sound.stop();
}

void df::Sound::pause() {
	sound.pause();
}

sf::Sound df::Sound::getSound() const {
	return sound;
}
