#ifndef DF_EVENTSTEP_H
#define DF_EVENTSTEP_H

#include "Event.h"

namespace df {

	const std::string STEP_EVENT = "df::step";

	class EventStep : public Event {

	private:
		int step_count;

	public:
		EventStep();

		EventStep(int step_count);

		void setStepCount(int step_count);

		int getStepCount() const;
	};
}

#endif //DF_EVENTSTEP_H
