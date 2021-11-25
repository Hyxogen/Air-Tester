#include "AirTester.h"

AirTester::AirTester() {
	m_Tests = new std::vector<Test*>();
}

AirTester::~AirTester() {
	delete m_Tests;
}

void AirTester::RunAll() {
	std::vector<Test*>::iterator it;
	
	for (Test* test : *m_Tests)
		test->TestBody();
}

Test* AirTester::AddTest(Test* test) {
	m_Tests->push_back(test);
	return test;
}

AirTester* AirTester::GetInstance() {
	static AirTester* instance = nullptr;
	if (instance == nullptr)
		instance = new AirTester();
	return instance;
}

Test::Test() {

}