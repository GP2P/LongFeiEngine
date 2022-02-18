#ifndef DF_EVENTOUT_H
#define DF_EVENTOUT_H

#include "Event.h"

namespace df {

	const std::string OUT_EVENT = "df::out";

	class EventOut : public Event {
	public:
		EventOut();
	};
}

#endif //DF_EVENTOUT_H
