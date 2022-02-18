#ifndef DF_EVENTVIEW_H
#define DF_EVENTVIEW_H

#include <string>
#include "Event.h"

namespace df {

	const std::string VIEW_EVENT = "df::view";

	class EventView : public Event {

	private:

		std::string tag;
		int value;
		bool delta;

	public:

		EventView();

		EventView(std::string tag, int value, bool delta);

		void setTag(std::string tag);

		std::string getTag() const;

		void setValue(int value);

		int getValue() const;

		void setDelta(bool delta);

		bool getDelta() const;
	};
}

#endif //DF_EVENTVIEW_H
