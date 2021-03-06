#ifndef DF_MANAGER_H
#define DF_MANAGER_H

#include <string>
#include "Event.h"

namespace df {

	class Manager {

	private:
		std::string m_type;
		bool m_is_started{};

	protected:
		void setType(std::string type);

	public:
		Manager();

		virtual ~Manager();

		std::string getType() const;

		// Return 0 if ok, else negative number
		virtual int startUp();

		virtual void shutDown();

		bool isStarted() const;

		int onEvent(const df::Event *p_event) const;
	};

}

#endif //DF_MANAGER_H
