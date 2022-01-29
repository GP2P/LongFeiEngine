#ifndef DF_LOGMANAGER_H
#define DF_LOGMANAGER_H

#include <string>
#include "Manager.h"

#define LM df::LogManager::getInstance()

namespace df {

	const std::string LOGFILE_NAME = "LongFei.log";

	class LogManager : public Manager {

	private:
		LogManager();

		LogManager(LogManager const &);

		void operator=(LogManager const &);

		bool do_flush;
		FILE *p_file;
		bool log_time_string;
		bool log_step_count;
		int log_level;

	public:
		// if logfile open, close it
		~LogManager();

		static LogManager &getInstance();

		// open logfile "LongFei.log"
		// Return 0 if ok, else negative number
		int startUp() override;

		// close logfile
		void shutDown() override;

		// set flush of logfile after each write
		void setFlush(bool doFlush = true);

		// default true
		void setLogTimeString(bool logTimeString = true);

		// default true
		void setLogStepCount(bool logStepCount = true);

		// return number of bytes written, -1 if error
		// log levels: 5 - error; 4 - repeated error; 3 - debug; 2 - repeated debug; 1 - log
		int writeLog(int logLevel = INT_MAX, const char *fmt = "log", ...) const;
	};
}

#endif //DF_LOGMANAGER_H