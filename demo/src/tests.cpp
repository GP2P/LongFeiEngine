#include <iostream>
#include "LogManager.h"
#include "GameManager.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Event.h"
#include "EventStep.h"
#include "Tester.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "Saucer.h"
#include "Hero.h"
#include "Star.h"
#include "ResourceManager.h"
#include "GameStart.h"

int LMTests();

int GMTests();

int VectorTests();

int ObjectTests();

int ObjectListTests();

int EventTests();

int WMTests();

int DMTests();

int tests();

#define TEST(test_name) \
  if (test_name) \
    pass++; \
  else \
    fail++;

int RMTests();

bool testGood();

bool testBad();

bool testBigBad();

void runDemo();

int main() {
//	std::cout << "Running engine tests:" << std::endl << std::endl;
//	tests();
	std::cout << "Running game demo:" << std::endl << std::endl;
	runDemo();
}

void runDemo() {
	// Start up game manager.
	if (GM.startUp()) {
		LM.writeLog(5, "Error starting game manager!");
		GM.shutDown();
	}

	// Set flush of logfile during development (when done, make false).
	LM.setFlush(true);

	RM.loadSprite("sprites/saucer-spr.txt", "saucer");
	RM.loadSprite("sprites/ship-spr.txt", "ship");
	RM.loadSprite("sprites/bullet-spr.txt", "bullet");
	RM.loadSprite("sprites/explosion-spr.txt", "explosion");
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	RM.loadSprite("sprites/gameover-spr.txt", "gameover");
	RM.loadSound("sounds/fire.wav", "fire");
	RM.loadSound("sounds/explode.wav", "explode");
	RM.loadSound("sounds/nuke.wav", "nuke");
	RM.loadSound("sounds/game-over.wav", "game over");
	RM.loadMusic("sounds/start-music.wav", "start music");

	// adjust view
	WM.setWorldBoundary(df::Box(df::Vector(), 80, DM.getVertical()));
//	WM.setViewBoundary(df::Box(df::Vector(), 80, DM.getVertical()));
	WM.setViewBoundary(df::Box(df::Vector(), DM.getHorizontal() + 5, DM.getVertical()));

	// Spawn some Stars.
	for (int i = 0; i < 16; i++)
		new Star;

	// Create GameStart object.
	new GameStart();

	// Run game (this blocks until game loop is over).
	GM.run();

	// Shut everything down.
	GM.shutDown();
}

int tests() {
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

	// Event Tests
	int EventTestResult = EventTests();
	if (EventTestResult != 0) {
		std::cout << "Event test result: " << EventTestResult << std::endl;
		return -1;
	} else
		std::cout << "Event Test passed with result: ok" << std::endl;

	// WM Tests
	int WMTestResult = WMTests();
	if (WMTestResult != 0) {
		std::cout << "WM test result: " << WMTestResult << std::endl;
		return -1;
	} else
		std::cout << "WM Test passed with result: ok" << std::endl;

	// DM Tests
	int DMTestResult = DMTests();
	if (DMTestResult != 0) {
		std::cout << "DM test result: " << DMTestResult << std::endl;
		return -1;
	} else
		std::cout << "DM Test passed with result: ok" << std::endl;

	// RM Tests
	int RMTestResult = RMTests();
	if (RMTestResult != 0) {
		std::cout << "RM test result: " << RMTestResult << std::endl;
		return -1;
	} else
		std::cout << "RM Test passed with result: ok" << std::endl;

	std::cout << "All tests passed!" << std::endl;

	return 0;
}

int LMTests() {
	// start LM
//	LM.setFlush(true);
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
	Tester o1 = Tester(123, 0, "LongFei");
	o1.setPosition(df::Vector(1, 2));
	o1.setPhoneNumber(123456789);
	o1.setName("o1");
	o1.setAge(1);
	df::Object o2 = df::Object();
	o2.setType("src");
	if (o2.getType() == "src")
		if (o1.getPosition() == df::Vector(1, 2)) {
			o2.setId(3);
			if (o2.getId() == 3)
				if (o1.getType() == "Tester")
					if (o1.getAge() == 1)
						if (o1.getName() == "o1")
							if (o1.getPhoneNumber() == 123456789)
								return 0;
		}
	return -1;
}

int ObjectListTests() {
	df::ObjectList ol = df::ObjectList();
	if (!ol.isEmpty())
		return -1;
	df::Object o1 = df::Object();
	o1.setType("src");
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
				if (oli.currentObject() == &o3) {
					oli.next();
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
	}
	return -1;
}

int EventTests() {
	df::EventStep Step = df::EventStep();
	df::Event Event = df::Event();
	Tester tester = Tester();
	if (Step.getType() == "df::step") {
		Step.setType("myStep");
		if (Step.getType() == "myStep")
			if (tester.getAge() == 0)
				if (tester.eventHandler(&Step))
					if (tester.getAge() == 1)
						if (tester.eventHandler(&Event))
							if (tester.getAge() == 0)
								return 0;
	}
	return -1;
}

int WMTests() {
	// clear all Objects from WM
	df::ObjectList list = df::ObjectList(WM.getAllObjects());
	auto oli = df::ObjectListIterator(&list);
	while (!oli.isDone()) {
		WM.markForDelete(oli.currentObject());
		oli.next();
	}
	WM.update();
	if (!WM.getAllObjects().isEmpty())
		return -1;

	// add Tester(Object) to WM
	Tester *tester = new Tester(1, 2, "3");
	if (!WM.getAllObjects().isEmpty()) {
		WM.markForDelete(tester);
		WM.update();
		if (WM.getAllObjects().isEmpty()) {
			return 0;
		}
	}
	return -1;
}

int DMTests() {
	DM.startUp();
	if (DM.getHorizontalPixels() != 1024 || DM.getVerticalPixels() != 768 || DM.getHorizontal() != 80 ||
	    DM.getVertical() != 24)
		return -1;
	auto *tester = new Tester(1, 2, "Hello World Text");
	DM.drawCh(df::Vector(0, 0), 'H', df::RED);
	DM.drawString(df::Vector(10, 10), "ello, World!", df::CENTER_JUSTIFIED, df::RED);
	return DM.swapBuffers();
}

int RMTests() {

	// Start up LogManager.
	if (LM.startUp()) {
		LM.writeLog(5, "main(): Error starting log manager!");
		return 1;
	}

	// Start up ResourceManager.
	if (RM.startUp()) {
		LM.writeLog(5, "main(): Error starting resource manager!");
		return 1;
	}

	// Run tests.
	int pass = 0, fail = 0;
	TEST(testGood());
	TEST(testBad());
	TEST(testBigBad());
	LM.writeLog(5, "----------------------");
	LM.writeLog(5, "Summary: %d of %d tests pass.",
	            pass, pass + fail);
	if (fail != 0)
		LM.writeLog(5, "FAILURE");
	else
		LM.writeLog(5, "SUCCESS");
	LM.writeLog(5, "----------------------");

	// Shut everything down.
	RM.shutDown();
	LM.shutDown();

	return 0;
}

// Load good sprite.
// Return TRUE if test passes, else FALSE.
bool testGood() {
	if (RM.loadSprite("sprites/good-spr.txt", "good") != 0) {
		LM.writeLog(5, "%s: FAIL - Error loading good sprite!",
		            __FUNCTION__);
		return false;
	}

	LM.writeLog(5, "%s: PASS", __FUNCTION__);
	return true;
}

// Load bad sprite.
// Return TRUE if test passes, else FALSE.
bool testBad() {

	if (RM.loadSprite("sprites/bad-spr.txt", "bad") == 0) {
		LM.writeLog(5, "%s: FAIL - Loaded bad sprite, but should not have!",
		            __FUNCTION__);
		return false;
	}

	LM.writeLog(5, "%s: PASS", __FUNCTION__);
	return true;
}

// Load large, bad sprite.
// Return TRUE if test passes, else FALSE.
bool testBigBad() {

	if (RM.loadSprite("sprites/map-spr.txt", "map") == 0) {
		LM.writeLog(5, "%s: FAIL - Loaded map sprite, but should not have!",
		            __FUNCTION__);
		return false;
	}

	LM.writeLog(5, "%s: PASS", __FUNCTION__);
	return true;
}
