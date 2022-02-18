#ifndef DF_EVENT_H
#define DF_EVENT_H

#include <string>

namespace df {

	const std::string UNDEFINED_EVENT = "df::undefined";

	class Event {

	private:
		std::string type;

	public:
		Event();

		virtual ~Event();

		void setType(std::string type);

		std::string getType() const;
	};
}

#endif //DF_EVENT_H
