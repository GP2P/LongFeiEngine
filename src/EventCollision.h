#ifndef DF_EVENTCOLLISION_H
#define DF_EVENTCOLLISION_H

#include "Vector.h"
#include "Object.h"

namespace df {

	const std::string COLLISION_EVENT = "df-collision";

	class EventCollision : public Event {

	private:
		Vector position;
		Object *p_object1; // the moving object
		Object *p_object2; // the other object

	public:
		EventCollision();

		EventCollision(Object *p_object1, Object *p_object2, Vector position);

		void setObject1(Object *p_object1);

		Object *getObject1() const;

		void setObject2(Object *p_object2);

		Object *getObject2() const;

		void setPosition(Vector position);

		Vector getPosition() const;
	};
}

#endif //DF_EVENTCOLLISION_H
