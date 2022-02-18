#include "Manager.h"
#include "Event.h"
#include "ObjectList.h"
#include "WorldManager.h"
#include "ObjectListIterator.h"

df::Manager::Manager() {
	m_type = "";
	m_is_started = false;
	setType("Manager");
}

int df::Manager::startUp() {
	m_is_started = true;
	return 0;
}

void df::Manager::shutDown() {
	m_is_started = false;
}

df::Manager::~Manager() {
	m_is_started = false;
}

bool df::Manager::isStarted() const {
	return m_is_started;
}

void df::Manager::setType(std::string type) {
	m_type = type;
}

std::string df::Manager::getType() const {
	return m_type;
}

int df::Manager::onEvent(const Event *p_event) const {
	int count = 0;
	ObjectList allObjects = WM.getAllObjects();
	ObjectListIterator oli = ObjectListIterator(&allObjects);
	while (!oli.isDone()) {
		oli.currentObject()->eventHandler(p_event);
		oli.next();
		count++;
	}
	return count;
}
