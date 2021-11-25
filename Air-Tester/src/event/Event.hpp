#pragma once

namespace tester {
	namespace event {

		class Event {
		public:
			virtual long long GetID() const = 0;
		};

	}
}