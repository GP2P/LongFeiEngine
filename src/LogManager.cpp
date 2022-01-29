#include "LogManager.h"
#include "utility.h"

df::LogManager::LogManager() {
	do_flush = false;
	p_file = nullptr;
	log_time_string = true;
	log_step_count = true;
	log_level = 0;
	setType("LogManager");
}

df::LogManager &df::LogManager::getInstance() {
	static LogManager logManager;
	return logManager;
}

int df::LogManager::startUp() {
	p_file = fopen(LOGFILE_NAME.c_str(), "w");
	if (p_file != nullptr) {
		// generate log headers based on log style
		if (log_time_string && log_step_count)
			fprintf(p_file, "Time\t\tTick\tMessage\n");
		else if (log_time_string)
			fprintf(p_file, "Time\t\tMessage\n");
		else if (log_step_count)
			fprintf(p_file, "Tick\tMessage\n");
		fprintf(p_file, "----------------------------\n");
		return Manager::startUp();
	} else
		return -1;
}

void df::LogManager::shutDown() {
	if (p_file != nullptr) {
		if (fclose(p_file) == 0)
			Manager::shutDown();
		else
			writeLog(5, "LogManager won't shut down: logfile can't be closed");
	}
}

df::LogManager::~LogManager() {
	if (p_file != nullptr) {
		if (fclose(p_file) == 0)
			Manager::~Manager();
		else
			writeLog(5, "LogManager won't shut down: logfile can't be closed");
	}
}

void df::LogManager::setFlush(bool doFlush) {
	do_flush = doFlush;
}

void df::LogManager::setLogTimeString(bool logTimeString) {
	log_time_string = logTimeString;
}

void df::LogManager::setLogStepCount(bool logStepCount) {
	log_step_count = logStepCount;
}

int df::LogManager::writeLog(int logLevel, const char *fmt, ...) const {
	if (logLevel >= this->log_level) {
		// TODO: add tick if log_step_count true
		// message head
		if (log_time_string && log_step_count)
			fprintf(p_file, "%s\tstep\t", getTimeString());
		else if (log_time_string)
			fprintf(p_file, "%s\t", getTimeString());
		else if (log_step_count)
			fprintf(p_file, "step\t");
		else
			fprintf(p_file, "Message: ");

		// message body
		va_list args;
		va_start(args, fmt);
		int numOfBytesWritten = vfprintf(p_file, fmt, args);
		va_end(args);
		fprintf(p_file, "\n");

		// flush output
		if (do_flush) {
			fflush(p_file);
		}
		return numOfBytesWritten;
	} else
		return 0;
}
