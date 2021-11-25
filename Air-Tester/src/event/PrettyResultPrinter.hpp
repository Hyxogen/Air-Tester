#pragma once
#include "AirEventListener.hpp"

namespace tester {
	namespace event {

		class PrettyResultPrinter : public AirEventListener {
		public:
			PrettyResultPrinter();

			void OnTesterStart() const override;

			void OnTesterStop() const override;

			void OnTestGroupStart(TestGroup* testGroup) const override;

			void OnTestStart(Test* test) const override;

			void OnTestGroupFinish(TestGroup* testGroup) const override;

			void OnTestFinish(Test* test) const override;

			void OnError(std::string file, int line, std::string message) const override;
		};
	}
}