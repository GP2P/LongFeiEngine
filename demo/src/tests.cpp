#include <iostream>
#include "LogManager.h"
#include "GameManager.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

int LMTests();

int GMTests();

int VectorTests();

int ObjectTests();

int ObjectListTests();

int main() {
	std::cout << "Starting LongFei Engine..." << std::endl << std::endl;

	// LM Tests
	int LMTestResult = LMTests();
	if (LMTestResult != 3 + 8 + 13 + 13 + 38) {
		std::cout << "LM test result: " << LMTestResult << std::endl;
		return -1;
	} else
		std::cout << "LM Test passed with result: " << LMTestResult << " bytes written" << std::endl;

	// GM Tests
	int GMTestResult = GMTests();
	if (GMTestResult != 0) {
		std::cout << "GM test result: " << GMTestResult << std::endl;
		return -1;
	} else
		std::cout << "GM Test passed with result: ok" << std::endl;

	// Vector Tests
	int VectorTestResult = VectorTests();
	if (VectorTestResult != 0) {
		std::cout << "Vector test result: " << VectorTestResult << std::endl;
		return -1;
	} else
		std::cout << "Vector Test passed with result: ok" << std::endl;

	// Object Tests
	int ObjectTestResult = ObjectTests();
	if (ObjectTestResult != 0) {
		std::cout << "Object test result: " << ObjectTestResult << std::endl;
		return -1;
	} else
		std::cout << "Object Test passed with result: ok" << std::endl;

	// ObjectList and ObjectListIterator Tests
	int ObjectListTestResult = ObjectListTests();
	if (ObjectListTestResult != 0) {
		std::cout << "ObjectList test result: " << ObjectListTestResult << std::endl;
		return -1;
	} else
		std::cout << "ObjectList Test passed with result: ok" << std::endl;
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
	if (GM.startUp() == 0)
		if (GM.isStarted())
			if (GM.getType() == "GameManager")
				if (!GM.getGameOver())
					if (GM.getFrameTime() == 33)
						return 0;
	return -1;
}

int VectorTests() {
	df::Vector v1 = df::Vector();
	v1.setX(1);
	v1.setY(2);
	df::Vector v2 = df::Vector(2, 1);
	v2.setXY(1, 2);
	if (v1.getX() == 1 && v1.getY() == 2 && v2.getX() == 1 && v2.getY() == 2)
		if (v1 == v2)
			if (v1.toString() == "(1, 2)" && v2.toString() == "(1, 2)") {
				v1.scale(2);
				v1.normalize();
				v2.normalize();
				if (v1 == v2 && v1.getMagnitude() == v2.getMagnitude())
					return 0;
			}
	return -1;
}

int ObjectTests() {
	df::Object o1 = df::Object();
	o1.setPosition(df::Vector(1, 2));
	df::Object o2 = df::Object();
	o2.setType("test");
	if (o2.getType() == "test")
		if (o1.getPosition() == df::Vector(1, 2)) {
			o2.setId(3);
			if (o2.getId() == 3)
				return 0;
		}
	return -1;
}

int ObjectListTests() {
	df::ObjectList ol = df::ObjectList();
	if (!ol.isEmpty())
		return -1;
	df::Object o1 = df::Object();
	o1.setType("test");
	ol.insert(&o1);
	auto oli = df::ObjectListIterator(&ol);
	df::Object o2 = df::Object();
	o2.setType("test2");
	ol.insert(&o2);
	df::Object o3 = df::Object();
	o3.setType("test3");
	ol.insert(&o3);
	oli.first();
	if (oli.currentObject() == &o1) {
		oli.next();
		if (oli.currentObject() == &o2)
			if (ol.getCount() == 3) {
				oli.last();
				if (oli.currentObject() == &o3)
					if (oli.isDone())
						if (ol.remove(&o2) == 1) {
							ol.clear();
							if (ol.isEmpty()) {
								auto ol2 = df::ObjectList();
								ol2.insert(&o1);
								oli.setList(&ol2);
								if (oli.currentObject() == &o1)
									return 0;
							}
						}
			}
	}
	return -1;
}
