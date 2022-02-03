#include "Tester.h"

Tester::Tester() {
	age = 0;
	name = "";
	phone_number = 0;
	setType("Tester");
}

Tester::Tester(int phone_number, int age, std::string name) {
	setType("Tester");
	setPhoneNumber(phone_number);
	setAge(age);
	setName(name);
}

Tester::~Tester() {
	df::Object::~Object();
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
	} else if (p_e->getType() == "lf::undefined") {
		age--;
		return 1;
	}
	return Object::eventHandler(p_e);
}
