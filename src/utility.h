#ifndef DF_UTILITY_H
#define DF_UTILITY_H

#include "Vector.h"
#include "Box.h"
#include "Object.h"

namespace df {

	char *getTimeString();

	bool positionsIntersect(Vector p1, Vector p2);

	bool boxIntersectsBox(Box b1, Box b2);

	Box getWorldBox(const Object *p_o);

	Box getWorldBox(const Object *p_o, Vector position);

	Vector worldToView(Vector worldPosition);
}

#endif //DF_UTILITY_H
