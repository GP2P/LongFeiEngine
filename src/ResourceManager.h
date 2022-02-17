#ifndef DF_RESOURCEMANAGER_H
#define DF_RESOURCEMANAGER_H

#include "SpriteResourceManager.h"
#include "Sprite.h"
#include "Sound.h"
#include "Music.h"

#define RM df::ResourceManager::getInstance()

namespace df {

	const int MAX_SOUNDS = 100;
	const int MAX_MUSICS = 50;

	class ResourceManager : public SpriteResourceManager {

	private:
		ResourceManager();

		ResourceManager(ResourceManager const &);

		void operator=(ResourceManager const &);

		Sprite *p_sprite[MAX_SPRITES];
		int spriteCount;
		Sound sound[MAX_SOUNDS];
		int soundCount;
		Music music[MAX_MUSICS];
		int musicCount;

	public:
		static ResourceManager &getInstance();

		int startUp() override;

		// free up any allocated Sprites, Music and Sounds
		void shutDown() override;

		// load Sprite from file, assign indicated label to Sprite
		// return 0 if ok, else -1
//		int loadSprite(std::string filename, std::string label);

		// unload Sprite with indicated label
		// return 0 if ok, else -1
//		int unloadSprite(std::string label);

		// find Sprite with indicated label
		// return pointer to it if found, else NULL
//		Sprite *getSprite(std::string label) const;

		// load sound from file
		// return 0 if ok, else -1
		int loadSound(std::string filename, std::string label);

		// remove Sound with indicated label
		// return 0 if ok, else -1
		int unloadSound(std::string label);

		// find Sound with indicated label
		// return pointer to it if found, else NULL
		Sound *getSound(std::string label);

		// associate file with Music
		// return 0 if ok, else -1
		int loadMusic(std::string filename, std::string label);

		// remove label for Music with indicated label
		// return 0 if ok, else -1
		int unloadMusic(std::string label);

		// find Music with indicated label
		// return pointer to it if found, else NULL
		Music *getMusic(std::string label);
	};
}

#endif //DF_RESOURCEMANAGER_H
