#ifndef DF_WORLDMANAGER_H
#define DF_WORLDMANAGER_H

#include "Manager.h"
#include "ObjectList.h"

#define WM df::WorldManager::getInstance()

namespace df {
	class WorldManager : public Manager {
	private:
		WorldManager();

		WorldManager(WorldManager const &);

		void operator=(WorldManager const &);

		ObjectList update_list;
		ObjectList delete_list;
		Box worldBoundary;
		Box viewBoundary;
		Object *p_focus_object;

	public:

		const int MAX_ALTITUDE = 4;

		static WorldManager &getInstance();

		int startUp() override;

		void shutDown() override;

		// insert Object into world, return 0 if ok, else −1
		int insertObject(Object *p_o);

		// remove Object from world, return 0 if ok, else −1
		int removeObject(Object *p_o);

		ObjectList getAllObjects() const;

		ObjectList objectsOfType(std::string type) const;

		void update();

		void draw();

		int markForDelete(Object *p_o);

		ObjectList getCollisions(Object *p_o, Vector position) const;

		// return 0 if moved, else −1
		int moveObject(Object *p_Object, Vector newPosition);

		const Box &getWorldBoundary() const;

		void setWorldBoundary(const Box &worldBoundary);

		const Box &getViewBoundary() const;

		void setViewBoundary(const Box &viewBoundary);

		// view edge will not go beyond world boundary
		void setViewCenter(Vector newCenter);

		// set to NULL to stop following
		int setViewFocus(Object *p_o);
	};
}

#endif //DF_WORLDMANAGER_H
