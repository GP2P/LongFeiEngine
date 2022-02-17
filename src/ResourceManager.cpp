#include "ResourceManager.h"

df::ResourceManager::ResourceManager() {
//	p_sprite = new Sprite[MAX_SPRITES];
	setType("ResourceManager");
}

df::ResourceManager &df::ResourceManager::getInstance() {
	static df::ResourceManager instance;
	return instance;
}

int df::ResourceManager::startUp() {
	return SpriteResourceManager::startUp();
}

void df::ResourceManager::shutDown() {
	SpriteResourceManager::shutDown();
}
