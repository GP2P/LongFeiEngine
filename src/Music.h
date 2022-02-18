#ifndef DF_MUSIC_H
#define DF_MUSIC_H

#include <SFML/Audio/Music.hpp>

namespace df {
	class Music {

	private:

		sf::Music music;
		std::string label;

		Music(Music const &);

		void operator=(Music const &);

	public:

		Music();

		int loadMusic(std::string filename);

		void setLabel(std::string label);

		std::string getLabel() const;

		void play(bool loop = true);

		void stop();

		void pause();

		sf::Music *getMusic();

	};
}

#endif //DF_MUSIC_H
