#include <iostream>
#include "LogManager.h"
#include "GameManager.h"

int LMTests();

int GMTests();

int main() {
	std::cout << "Starting LongFei Engine..." << std::endl << std::endl;

	// LM Tests
	int LMTestResult = LMTests();
	if (LMTestResult != 3 + 8 + 13 + 13 + 38) {
		std::cout << "LM test result: " << LMTestResult << std::endl;
		return -1;
	} else
		std::cout << "LM Test passed with result: " << LMTestResult << std::endl;

	// GM Tests
	int GMTestResult = GMTests();
	if (GMTestResult != 0) {
		std::cout << "GM test result: " << GMTestResult << std::endl;
		return -1;
	} else
		std::cout << "GM Test passed with result: ok" << std::endl;

	return 0;
}

int LMTests() {
	// start LM
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

	std::cout << "Running LM tests..." << std::endl;
	int bytes = 0;
	bytes += LM.writeLog();
	bytes += LM.writeLog(2, "float is %f", 2.33);
	bytes += LM.writeLog(2, "string is %s", "abc");
	bytes += LM.writeLog(2, "int is %i, float is %f, string is %s", 2, 2.33, "abc");
	return bytes;
}

int GMTests() {
	return GM.startUp();
}
