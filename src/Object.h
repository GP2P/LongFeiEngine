#ifndef DF_OBJECT_H
#define DF_OBJECT_H

#include <string>
#include "Vector.h"
#include "Event.h"

namespace df {
	class Object {

	private:
		int id;
		std::string type;
		Vector position;

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
	};
}

#endif //DF_OBJECT_H
