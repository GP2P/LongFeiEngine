#include <ctime>
#include <cstdio>
#include "utility.h"

char *df::getTimeString() {
	static char time_str[30];

//	TODO: error check system calls
	time_t now;
	time(&now);
	struct tm *p_time = localtime(&now);

	sprintf(time_str, "%02d:%02d:%02d",
	        p_time->tm_hour,
	        p_time->tm_min,
	        p_time->tm_sec);
	return time_str;
}
