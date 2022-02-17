#ifndef DF_FRAME_H
#define DF_FRAME_H

#include <string>
#include "Vector.h"
#include "Color.h"

namespace df {

	class Frame {

	private:
		int width;
		int height;
		std::string frameContent;

	public:
		Frame();

		Frame(int width, int height, std::string frameContent);

		void setWidth(int width);

		int getWidth() const;

		void setHeight(int height);

		int getHeight() const;

		void setFrameContent(std::string frameContent);

		std::string getFrameContent() const;

		void setString(std::string frameContent);

		std::string getString() const;

		// return 0 if ok, else −1
		// top−left coordinate is (0,0)
		int draw(Vector position, Color color) const;
	};
}

#endif //DF_FRAME_H
