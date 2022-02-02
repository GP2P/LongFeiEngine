#include "ObjectList.h"
#include "ObjectListIterator.h"

df::ObjectListIterator::ObjectListIterator() {

}

df::ObjectListIterator::ObjectListIterator(const df::ObjectList *p_list) {
	if (p_list != nullptr) {
		this->p_list = p_list;
		first();
	}
}

void df::ObjectListIterator::first() {
	index = 0;
}

void df::ObjectListIterator::last() {
	index = p_list->count - 1;
}

void df::ObjectListIterator::next() {
	if (index < p_list->count) {
		index++;
	}
}

bool df::ObjectListIterator::isDone() const {
	return (index == p_list->count - 1);
}

df::Object *df::ObjectListIterator::currentObject() const {
	return p_list->p_list[index];
}

df::ObjectListIterator &df::ObjectListIterator::operator=(const df::ObjectListIterator &other) {
}

void df::ObjectListIterator::setList(const df::ObjectList *p_list) {
	if (p_list != nullptr) {
		this->p_list = p_list;
		index = 0;
	}
}
