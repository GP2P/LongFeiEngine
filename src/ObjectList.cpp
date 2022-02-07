#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "LogManager.h"

df::ObjectList::ObjectList() {
	count = 0;
	max_count = 2;
	p_list = (Object **) malloc(sizeof(Object *) * max_count);
}

df::ObjectList::~ObjectList() {
	free(p_list);
}

df::ObjectList::ObjectList(const df::ObjectList &other) {
	p_list = (Object **) malloc(sizeof(Object *) * other.max_count);
	if (p_list == NULL) {
		LM.writeLog(5, "ObjectList::ObjectList(): Error allocating memory");
		return;
	}
	memcpy(p_list, other.p_list, sizeof(Object *) * other.max_count);
	max_count = other.max_count;
	count = other.count;
}

df::ObjectList &df::ObjectList::operator=(const df::ObjectList &other) {
	if (this != &other) {
		free(p_list);
		p_list = (Object **) malloc(sizeof(Object *) * other.max_count);
		if (p_list == NULL) {
			LM.writeLog(5, "Error: ObjectList::operator=() - Could not allocate memory.");
			return *this;
		}
		memcpy(p_list, other.p_list, sizeof(Object *) * other.max_count);
		max_count = other.max_count;
		count = other.count;
	}
	return *this;
}

int df::ObjectList::insert(df::Object *p_o) {
	if (isFull()) {
		Object **temp = (Object **) realloc(p_list, 2 * sizeof(Object *) * max_count);
		p_list = temp;
		max_count *= 2;
	}
	if (count == 0) {
		p_list = new Object *[max_count];
	}
	p_list[count] = p_o;
	count++;
	return count - 1;
}

int df::ObjectList::remove(df::Object *p_o) {
	for (int i = 0; i < count; i++) {
		if (p_list[i] == p_o) {
			for (int j = i; j < count - 1; j++)
				p_list[j] = p_list[j + 1];
			count--;
			return i;
		}
	}
	return -1;
}

void df::ObjectList::clear() {
	delete[] p_list;
	p_list = nullptr;
	count = 0;
}

int df::ObjectList::getCount() const {
	return count;
}

bool df::ObjectList::isEmpty() const {
	return count == 0;
}

bool df::ObjectList::isFull() const {
	return count >= max_count;
}

df::ObjectList df::ObjectList::operator+(df::ObjectList other) {
	ObjectList result = *this;
	ObjectListIterator li(&other);

	for (li.first(); !li.isDone(); li.next()) {
		Object *p_o = li.currentObject();
		result.insert(p_o);
	}

	return result;
}

df::ObjectList &df::ObjectList::operator+=(const df::ObjectList &other) {
	ObjectListIterator li(&other);

	for (li.first(); !li.isDone(); li.next()) {
		Object *p_o = li.currentObject();
		insert(p_o);
	}

	return *this;
}

bool df::ObjectList::operator==(const df::ObjectList &other) const {
	if (count != other.count) return false;
	for (int i = 0; i < count; i++) {
		if (p_list[i] != other.p_list[i]) return false;
	}
	return true;
}

bool df::ObjectList::operator!=(const df::ObjectList &other) const {
	return !(*this == other);
}
