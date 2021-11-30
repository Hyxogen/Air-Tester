#include "BriefResultPrinter.hpp"
#include <iostream>
#include "internal/InternalAirTester.hpp"

#define ANSII_RESET "\033[0m"
/*
DARK_GRAY="\033[1;30m"
LIGHT_RED="\033[1;31m"
LIGHT_GREEN="\033[1;32m"
YELLOW="\033[1;33m"
LIGHT_BLUE="\033[1;34m"
LIGHT_PURPLE="\033[1;35m"
LIGHT_CYAN="\033[1;36m"
WHITE="\033[1;37m"
*/
#define ANSII_COLOR_BLACK "\033[0;30m"
#define ANSII_COLOR_RED "\033[0;31m"
#define ANSII_COLOR_GREEN "\033[0;32m"
#define ANSII_COLOR_ORANGE "\033[0;33m"
#define ANSII_COLOR_BLUE "\033[0;34m"
#define ANSII_COLOR_PURPLE "\033[0;35m"
#define ANSII_COLOR_CYAN "\033[0;36m"
#define ANSII_COLOR_LIGHT_GRAY "\033[0;37m"

#define ANSII_COLOR_DARK_GRAY "\033[1;30m"
#define ANSII_COLOR_LIGT_RED "\033[1;31m"
#define ANSII_COLOR_LIGHT_GREEN "\033[1;32m"
#define ANSII_COLOR_YELLOW "\033[1;33m"
#define ANSII_COLOR_LIGHT_BLUE "\033[1;34m"
#define ANSII_COLOR_LIGHT_PURPLE "\033[1;35m"
#define ANSII_COLOR_LIGHT_CYAN "\033[1;36m"
#define ANSII_COLOR_WHITE "\033[1;37m"

namespace tester {
	namespace event {

		BriefResultPrinter::BriefResultPrinter() {

		}

		void BriefResultPrinter::OnTesterStart() const {

		}

		void BriefResultPrinter::OnTesterStop() const {

		}

		void BriefResultPrinter::OnTestGroupStart(TestGroup* testGroup) const {
			std::cout << testGroup->m_Name << ": ";	
		}

		void BriefResultPrinter::OnTestStart(Test* test) const {
			(void)test;
		}

		void BriefResultPrinter::OnTestGroupFinish(TestGroup* testGroup) const {
			(void)testGroup;
			std::cout << std::endl;
		}

		void BriefResultPrinter::OnTestFinish(Test* test) const {
			if (!test->GetFailedCount())
				std::cout << ANSII_COLOR_GREEN << "OK " << ANSII_RESET;
			else
				std::cout << ANSII_COLOR_RED << "KO " << ANSII_RESET;
		}

		void BriefResultPrinter::OnError(std::string file, int line, std::string message) const {
			(void)file;
			(void)line;
			(void)message;
		}
	}
}