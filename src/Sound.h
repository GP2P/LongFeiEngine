#ifndef DF_SOUND_H
#define DF_SOUND_H

#include <SFML/Audio.hpp>

namespace df {
	class Sound {

	private:

		sf::Sound sound;
		sf::SoundBuffer soundBuffer;
		std::string label;

	public:

		Sound();

		int loadSound(std::string filename);

		void setLabel(std::string label);

		std::string getLabel() const;

		void play(bool loop = false);

		void stop();

		void pause();

		sf::Sound getSound() const;

	};
}

#endif //DF_SOUND_H
