#ifndef DF_OBJECT_H
#define DF_OBJECT_H

#include <string>
#include "Vector.h"
#include "Event.h"
#include "Animation.h"
#include "Box.h"

namespace df {

	enum Solidness {
		HARD,       // causes collisions and impedes
		SOFT,       // causes collision, but doesn't impede
		SPECTRAL,   // doesn't cause collisions
	};

	class Object {

	private:

		int id;
		std::string type;
		Box box;
		Vector position;
		Vector direction;
		float speed;
		int altitude;
		Solidness solidness;
		Animation animation;

	public:
		// construct Object with default values
		// add to game world (WorldManager)
		Object();

		// destroy Object
		// remove from game world (WorldManager)
		virtual ~Object();

		void setId(int id);

		int getId() const;

		void setType(std::string type);

		std::string getType() const;

		void setPosition(Vector position);

		Vector getPosition() const;

		// return 0 if ignored, else 1
		virtual int eventHandler(const Event *p_event);

		virtual int draw();

		int getAltitude() const;

		// set altitude of Object, with checks for range [0, MAX_ALTITUDE]
		// return 0 if altitude set, else -1
		int setAltitude(int altitude);

		float getSpeed() const;

		void setSpeed(float speed);

		Vector getDirection() const;

		void setDirection(Vector direction);

		Vector getVelocity() const;

		void setVelocity(Vector velocity);

		Vector predictPosition();

		// return true if HARD or SOFT
		bool isSolid() const;

		// return 0 if ok, else -1
		void setSolidness(Solidness solidness);

		Solidness getSolidness() const;

		// return 0 if ok, else -1
		int setSprite(std::string spriteLabel);

		void setAnimation(Animation animation);

		Animation getAnimation() const;

		void setBox(Box box);

		Box getBox() const;
	};
}

#endif //DF_OBJECT_H
