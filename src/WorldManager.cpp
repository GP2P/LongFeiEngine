#include "WorldManager.h"
#include "LogManager.h"
#include "ObjectListIterator.h"

df::WorldManager::WorldManager() {
	update_list.clear();
	delete_list.clear();
	setType("WorldManager");
}

df::WorldManager &df::WorldManager::getInstance() {
	static WorldManager instance;
	return instance;
}

int df::WorldManager::startUp() {
	update_list.clear(); // clear the update list
	delete_list.clear(); // clear the update list
	return Manager::startUp();
}

void df::WorldManager::shutDown() {
	ObjectList ol = update_list;
	auto oli = ObjectListIterator(&ol);
	while (!oli.isDone()) {
		delete oli.currentObject();
		oli.next();
	}

	update_list.clear(); // clear the update list
	delete_list.clear(); // clear the delete list
	Manager::shutDown();
}

int df::WorldManager::insertObject(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(4, "WorldManager::insertObject(): NULL object");
		return -1;
	} else if (update_list.insert(p_o) == -1) {
		LM.writeLog(4, "WorldManager::insertObject(): object not inserted");
		return -1;
	} else
		return 0;
}

int df::WorldManager::removeObject(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(4, "WorldManager::removeObject(): NULL object");
		return -1;
	} else if (update_list.remove(p_o) == -1) {
		LM.writeLog(4, "WorldManager::removeObject(): object not removed");
		return -1;
	} else
		return 0;
}

df::ObjectList df::WorldManager::getAllObjects() const {
	return update_list;
}

df::ObjectList df::WorldManager::objectsOfType(std::string type) const {
	ObjectList result = ObjectList();
	auto oli = ObjectListIterator(&update_list);
	while (!oli.isDone()) {
		if (oli.currentObject()->getType() == type)
			result.insert(oli.currentObject());
		oli.next();
	}
	return result;
}

void df::WorldManager::update() {
	// delete all objects in the delete list
	auto dli = ObjectListIterator(&delete_list);
	while (!dli.isDone()) {
		delete dli.currentObject();
		dli.next();
	}
	delete_list.clear();
}

int df::WorldManager::markForDelete(df::Object *p_o) {
	if (p_o == NULL) {
		LM.writeLog(4, "WorldManager::markForDelete(): NULL object");
		return -1;
	} else if (delete_list.insert(p_o) == -1) {
		LM.writeLog(4, "WorldManager::markForDelete(): object not marked");
		return -1;
	} else
		return 0;
}
