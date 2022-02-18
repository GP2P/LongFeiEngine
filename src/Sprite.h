#ifndef DF_SPRITE_H
#define DF_SPRITE_H

#include "Color.h"
#include "Frame.h"

namespace df {
	class Sprite {

	private:
		int width;
		int height;
		int maxFrameCount;
		int frameCount;
		Color color;
		int slowdown; // amount of steps per frame, 0 for stop
		Frame *frames;
		std::string label;

		Sprite();

	public:

		~Sprite();

		Sprite(int maxFrameCount);

		void setWidth(int width);

		int getWidth() const;

		void setHeight(int height);

		int getHeight() const;

		int getFrameCount() const;

		void setFrameCount(int frameCount);

		Color getColor() const;

		void setColor(Color color);

		// return empty frame if out of range [0 , m frame count −1]
		Frame *getFrame(int index) const;

		int getSlowdown() const;

		void setSlowdown(int slowdown);

		std::string getLabel() const;

		void setLabel(const std::string label);

		// return -1 if frame array full, else 0
		int addFrame(Frame p_frame);

		// return 0 if ok, else -1
		int draw(int frameNumber, Vector position) const;
	};
}

#endif //DF_SPRITE_H
