#include "Tester.h"
#include "Color.h"
#include "DisplayManager.h"
#include "LogManager.h"

Tester::Tester() {
	age = 0;
	name = "";
	phone_number = 0;
	setType("Tester");
	setSolidness(df::SPECTRAL);
	setVelocity(df::Vector(-0.2, 0.1));
	setAltitude(1);
	df::Vector p((float) (rand() % (int) DM.getHorizontal()), (float) (rand() % (int) DM.getVertical()));
	setPosition(p);
}

Tester::Tester(int phone_number, int age, std::string name) {
	setType("Tester");
	setPhoneNumber(phone_number);
	setAge(age);
	setName(name);
}

Tester::~Tester() {
}

int Tester::getPhoneNumber() {
	return phone_number;
}

void Tester::setPhoneNumber(int new_phone_number) {
	phone_number = new_phone_number;
}

int Tester::getAge() {
	return age;
}

void Tester::setAge(int new_age) {
	age = new_age;
}

std::string Tester::getName() {
	return name;
}

void Tester::setName(std::string new_name) {
	name = new_name;
}

int Tester::eventHandler(const df::Event *p_e) {
	if (p_e->getType() == "myStep") {
		age++;
		return 1;
//	} else if (p_e->getType() == "df::step") {
//		LM.writeLog(2, "Tester: Step event received");
	} else if (p_e->getType() == "df::undefined") {
		age--;
		return 1;
	} else if (p_e->getType() == "df::out_event") {
		df::Vector pos((float) (DM.getHorizontal() + rand() % 20), (float) (rand() % DM.getVertical()));
		setPosition(pos);
		setVelocity(df::Vector((float) -1.0 / (rand() % 9 + 2), 0));
	}
	return Object::eventHandler(p_e);
}

int Tester::draw() {
	DM.drawCh(getPosition(), 'T', df::RED);
	return 0;
}
