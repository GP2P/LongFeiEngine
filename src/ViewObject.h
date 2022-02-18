#ifndef DF_VIEWOBJECT_H
#define DF_VIEWOBJECT_H

#include "Object.h"

namespace df {

	enum ViewObjectLocation {
		UNDEFINED = -1,
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT,
	};

	class ViewObject : public Object {

	private:

		std::string viewString;
		int value;
		bool drawValue;
		bool haveBorder;
		Color color;
		ViewObjectLocation location;

	public:

		ViewObject();

		virtual int draw() override;

		virtual int eventHandler(const Event *p_e) override;

		void setLocation(ViewObjectLocation location);

		ViewObjectLocation getLocation() const;

		void setDrawValue(bool drawValue = true);

		bool getDrawValue() const;

		void setValue(int value);

		int getValue() const;

		void setBorder(bool haveBorder = true);

		bool getBorder() const;

		void setColor(Color color);

		Color getColor() const;

		void setViewString(std::string viewString);

		std::string getViewString() const;
	};
}

#endif //DF_VIEWOBJECT_H
