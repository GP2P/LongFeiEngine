#ifndef DF_TESTER_H
#define DF_TESTER_H

#include "Object.h"

class Tester : public df::Object {
private:
	int phone_number;
	int age;
	std::string name;

public:

	Tester();

	Tester(int phone_number, int age, std::string name);

	~Tester();

	int getPhoneNumber();

	void setPhoneNumber(int new_phone_number);

	int getAge();

	void setAge(int new_age);

	std::string getName();

	void setName(std::string new_name);

	int eventHandler(const df::Event *p_e) override;

	int draw() override;
};

#endif //DF_TESTER_H
