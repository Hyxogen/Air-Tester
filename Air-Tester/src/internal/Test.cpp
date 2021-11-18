#include <iostream>
#include "Test.hpp"

Test::Test()
{

}

void Test::Execute() {
	TestBody();
//	if (m_FailedTests) {
		std::cout << "Failed " << m_FailedTests << " tests for: " << GetTestName() << std::endl;
//	}
}

Test::~Test()
{

}
