#pragma once
#include "Event.hpp"
#include <internal/DataTypes.h>

namespace tester {
	namespace event {

		class EventListener {
		public:
			virtual bool OnEvent(Event &event) = 0;

			virtual uint8 GetPriority() const = 0;
		};
	}
}