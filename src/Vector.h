#ifndef DF_VECTOR_H
#define DF_VECTOR_H

#include <string>

namespace df {

	class Vector {

	private:
		float x;
		float y;

	public:

		// create vector with (X,Y)
		Vector(float x, float y);

		// default vector (x,y) is (0,0)
		Vector();

		void setX(float newX);

		float getX() const;

		void setY(float newY);

		float getY() const;

		void setXY(float newX, float newY);

		float getMagnitude() const;

		void normalize();

		void scale(float scale);

		Vector operator+(const Vector &other) const;

		Vector operator-(const Vector &other) const;

		Vector operator*(const Vector &other) const;

		Vector operator/(const Vector &other) const;

		bool operator==(const Vector &other) const;

		bool operator!=(const Vector &other) const;

		Vector &operator+=(const Vector &other);

		bool operator!() const;

		std::string toString() const;
	};
}

#endif //DF_VECTOR_H
