#pragma once
class TestGroup;
class Test;

namespace tester {
	namespace event {

		class AirEventListener {
		protected:
			AirEventListener();
		public:
			virtual void OnTesterStart() = 0;

			virtual void OnTesterStop() = 0;

			virtual void OnTestGroupStart(TestGroup* testGroup) = 0;

			virtual void OnTestStart(Test* test) = 0;

			virtual void OnTestGroupFinish(TestGroup* testGroup) = 0;

			virtual void OnTestFinish(Test* test) = 0;
		};
	}
}