#include "ResourceManager.h"
#include "LogManager.h"

df::ResourceManager::ResourceManager() {
	setType("ResourceManager");
}

df::ResourceManager &df::ResourceManager::getInstance() {
	static df::ResourceManager instance;
	return instance;
}

int df::ResourceManager::startUp() {
	soundCount = 0;
	musicCount = 0;
	return SpriteResourceManager::startUp();
}

void df::ResourceManager::shutDown() {
	SpriteResourceManager::shutDown();
}

int df::ResourceManager::loadSound(std::string filename, std::string label) {
	if (soundCount >= MAX_SOUNDS)
		LM.writeLog(5, "ResourceManager::loadSound(): Too many sounds");
	else if (sound[soundCount].loadSound(filename) == 0) {
		sound[soundCount].setLabel(label);
		soundCount++;
		return 0;
	} else
		LM.writeLog(5, "ResourceManager::loadSound(): Error loading sound %s", filename.c_str());
	return -1;
}

int df::ResourceManager::unloadSound(std::string label) {
	for (int i = 0; i < soundCount; i++)
		if (sound[i].getLabel() == label) {
			sound[i].stop();
			for (int j = i; j < soundCount - 1; j++)
				sound[j] = sound[j + 1];
			soundCount--;
			return 0;
		}
	LM.writeLog(5, "ResourceManager::unloadSound(): Sound %s not found", label.c_str());
	return -1;
}

df::Sound *df::ResourceManager::getSound(std::string label) {
	for (int i = 0; i < soundCount; i++)
		if (sound[i].getLabel() == label)
			return &sound[i];
	LM.writeLog(5, "ResourceManager::getSound(): Sound %s not found", label.c_str());
	return nullptr;
}

int df::ResourceManager::loadMusic(std::string filename, std::string label) {
	if (musicCount >= MAX_MUSICS)
		LM.writeLog(5, "ResourceManager::loadMusic(): Too many music tracks");
	else if (music[musicCount].loadMusic(filename) == 0) {
		music[musicCount].setLabel(label);
		musicCount++;
		return 0;
	} else
		LM.writeLog(5, "ResourceManager::loadMusic(): Error loading music %s", filename.c_str());
	return -1;
}

int df::ResourceManager::unloadMusic(std::string label) {
	for (int i = 0; i < musicCount; i++)
		if (music[i].getLabel() == label) {
			music[i].stop();
			music[i].setLabel("");
			return 0;
		}
	LM.writeLog(5, "ResourceManager::unloadMusic(): Music %s not found", label.c_str());
	return -1;
}

df::Music *df::ResourceManager::getMusic(std::string label) {
	for (int i = 0; i < musicCount; i++)
		if (music[i].getLabel() == label)
			return &music[i];
	LM.writeLog(5, "ResourceManager::getMusic(): Music %s not found", label.c_str());
	return nullptr;
}
