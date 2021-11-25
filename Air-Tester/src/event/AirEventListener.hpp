#pragma once
#include <string>

class TestGroup;
class Test;

namespace tester {
	namespace event {

		class AirEventListener {
		protected:
			AirEventListener();
		public:
			virtual void OnTesterStart() const = 0;

			virtual void OnTesterStop() const = 0;

			virtual void OnTestGroupStart(TestGroup* testGroup) const = 0;

			virtual void OnTestStart(Test* test) const = 0;

			virtual void OnTestGroupFinish(TestGroup* testGroup) const = 0;

			virtual void OnTestFinish(Test* test) const = 0;

			virtual void OnError(std::string file, int line, std::string message) const = 0;
		};
	}
}