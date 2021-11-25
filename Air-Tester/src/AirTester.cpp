#include "AirTester.h"

AirTester::AirTester() {
	m_Groups = new GroupList();
}

AirTester::~AirTester() {
	delete m_Groups;
}

void AirTester::RunAll() {
	for (TestGroup* group : *m_Groups) {
		group->RunAllTests();
	}
}

TestGroup* AirTester::GetTestGroup(std::string name) {
	for (TestGroup* group : *m_Groups) {
		if (group->m_Name == name)
			return group;
	}
	//Create test group if didn't already exist
	return AddTestGroup(new TestGroup(name));
}

TestGroup* AirTester::AddTestGroup(TestGroup* testGroup) {
	m_Groups->push_back(testGroup);
	return (testGroup);
}

AirTester* AirTester::GetInstance() {
	static AirTester* instance = nullptr;
	if (instance == nullptr)
		instance = new AirTester();
	return instance;
}

TestGroup::TestGroup(std::string name) : m_Name(name) {
	m_Tests = new TestList();
}

TestGroup::~TestGroup() {
	CleanUp();
	delete m_Tests;
}

void TestGroup::RunAllTests() {
	for (Test* test : *m_Tests)
		test->TestBody();
}

void TestGroup::AddTest(Test* test) {
	m_Tests->push_back(test);
}

int TestGroup::GetTestCount() const {
	return m_Tests->size();
}

void TestGroup::CleanUp() {
	for (Test* test : *m_Tests)
		delete test;
}

Test::Test() {

}

Test::~Test() {

}