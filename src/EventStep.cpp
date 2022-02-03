#include "EventStep.h"

df::EventStep::EventStep() {
	setType(STEP_EVENT);
}

df::EventStep::EventStep(int step_count) {
	setType(STEP_EVENT);
	setStepCount(step_count);
}

void df::EventStep::setStepCount(int step_count) {
	if (step_count >= 0) {
		this->step_count = step_count;
	}
}

int df::EventStep::getStepCount() const {
	return step_count;
}
