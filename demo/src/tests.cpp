#include <iostream>
//#include "DisplayManager.h"
#include "LogManager.h"

//df::DisplayManager display_manager;
//df::LogManager log_manager;

int LMTests();

int main() {
	std::cout << "Starting LongFei Engine..." << std::endl << std::endl;

	// start LM
	// df::LogManager &LM = df::LogManager::getInstance();
	LM.setFlush(true);
	LM.setLogTimeString(true);
	LM.setLogStepCount(true);
	if (LM.startUp() == 0) {
		if (LM.writeLog(3, "Started LogManager") == 18)
			std::cout << "LM started successfully" << std::endl;
		else
			std::cout << "Unexpected LogManager behavior" << std::endl;
	} else
		std::cout << "LM failed to start" << std::endl;

	// Tests
	int LMTestResult = LMTests();
	if (LMTestResult != 3 + 8 + 13 + 13 + 38) {
		std::cout << "LM test result: " << LMTestResult << std::endl;
		return LMTestResult;
	} else {
		std::cout << "LM Test passed with result: " << LMTestResult << std::endl;
		return 0;
	}
}

int LMTests() {
	std::cout << "Running LM tests..." << std::endl;
	int bytes = 0;
	bytes += LM.writeLog();
	bytes += LM.writeLog(2, "float is %f", 2.33);
	bytes += LM.writeLog(2, "string is %s", "abc");
	bytes += LM.writeLog(2, "int is %i, float is %f, string is %s", 2, 2.33, "abc");
	return bytes;
}
