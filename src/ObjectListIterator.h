#ifndef DF_OBJECTLISTITERATOR_H
#define DF_OBJECTLISTITERATOR_H

namespace df {

	class ObjectList;

	class ObjectListIterator {

	private:
		ObjectListIterator();

		int index;
		const ObjectList *p_list;

	public:
		// create iterator over indicated list
		ObjectListIterator(const ObjectList *p_list);

		// set iterator to first item in list
		void first();

		// reset to last object in list.
		void last();

		// set iterator to next item in list
		void next();

		// return true if at end of list
		bool isDone() const;

		// return pointer to current item in list, NULL if done/empty
		Object *currentObject() const;

		// assignment operator
		ObjectListIterator &operator=(const ObjectListIterator &other);

		// set to new List
		void setList(const ObjectList *p_list);
	};
}

#endif //DF_OBJECTLISTITERATOR_H
