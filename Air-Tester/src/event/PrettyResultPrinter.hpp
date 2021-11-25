#pragma once
#include "AirEventListener.hpp"

namespace tester {
	namespace event {

		class PrettyResultPrinter : public AirEventListener {
		public:
			PrettyResultPrinter();

			void OnTesterStart() override;

			void OnTesterStop() override;

			void OnTestGroupStart(TestGroup* testGroup) override;

			void OnTestStart(Test* test) override;

			void OnTestGroupFinish(TestGroup* testGroup) override;

			void OnTestFinish(Test* test) override;
		};
	}
}