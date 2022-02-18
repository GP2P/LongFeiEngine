#ifndef DF_BOX_H
#define DF_BOX_H

#include "Vector.h"

namespace df {
	class Box {

	private:

		Vector corner; // top left corner
		float width;
		float height;

	public:

		Box();

		Box(Vector corner, float width, float height);

		void setCorner(Vector corner);

		Vector getCorner() const;

		void setWidth(float width);

		float getWidth() const;

		void setHeight(float height);

		float getHeight() const;

		std::string toString() const;

		bool operator==(const Box &rhs) const;

		bool operator!=(const Box &rhs) const;

		void draw();

		void draw(Vector position);
	};
}

#endif //DF_BOX_H
