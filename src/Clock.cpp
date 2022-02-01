#include <sys/time.h>
#include "Clock.h"

struct timeval before_tv, after_tv;

Clock::Clock() {
	gettimeofday(&before_tv, NULL);
}

long int Clock::delta() {
	long int delta = split();
	gettimeofday(&before_tv, NULL);
	return delta;
}

long int Clock::split() const {
	gettimeofday(&after_tv, NULL);
	long int before_msec = before_tv.tv_sec * 1000000 + before_tv.tv_usec;
	long int after_msec = after_tv.tv_sec * 1000000 + after_tv.tv_usec;
	long int elapsed_time = after_msec - before_msec;
	return elapsed_time;
}
