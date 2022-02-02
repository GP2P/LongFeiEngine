#ifndef DF_OBJECTLIST_H
#define DF_OBJECTLIST_H

#include "Object.h"

namespace df {
	class ObjectListIterator;

	class ObjectList {
	private:
		int count;
		int max_count;
		Object **p_list;

	public:
		friend class ObjectListIterator;

		ObjectList();

		~ObjectList();

		// copy constructor
		ObjectList(const ObjectList &other);

		// assignment operator
		ObjectList &operator=(const ObjectList &other);

		// insert object pointer into end of list
		// return index of object* in list
		int insert(Object *p_o);

		// remove object pointer from list
		// return index of Object* if found, else -1
		int remove(Object *p_o);

		// clear list (setting count to 0)
		void clear();

		int getCount() const;

		bool isEmpty() const;

		bool isFull() const;

		ObjectList operator+(ObjectList other);

		ObjectList &operator+=(const ObjectList &other);

		bool operator==(const ObjectList &other) const;

		bool operator!=(const ObjectList &other) const;
	};
}

#endif //DF_OBJECTLIST_H
