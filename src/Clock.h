#ifndef DF_CLOCK_H
#define DF_CLOCK_H

class Clock {

private:

	long int previous_time;

public:

	// sets previous time to current time
	Clock();

	// return time elapsed since delta () was last called , −1 if error
	// resets previous time
	// units are microseconds
	long int delta();

	// return time elapsed since delta () was last called , −1 if error
	// does not reset previous time
	// units are microseconds
	long int split() const;
};

#endif //DF_CLOCK_H
