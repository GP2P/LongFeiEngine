#ifndef DF_ANIMATION_H
#define DF_ANIMATION_H

#include "Sprite.h"
#include "Box.h"

namespace df {
	class Animation {

	private:

		Sprite *p_sprite;
		std::string name;
		int index;
		int slowdownCounter;

	public:

		Animation();

		void setSprite(Sprite *sprite);

		Sprite *getSprite() const;

		void setName(std::string name);

		std::string getName() const;

		void setIndex(int index);

		int getIndex() const;

		void setSlowdownCounter(int slowdownCounter);

		int getSlowdownCounter() const;

		Box getBox() const;

		// return 0 if okay, else -1
		int draw(Vector position);
	};
}

#endif //DF_ANIMATION_H
