#pragma once

#include <vector>
#include <string>

class Test;
class TestGroup;

typedef std::vector<Test*> TestList;
typedef std::vector<TestGroup*> GroupList;

class TestGroup {
	int			m_FailedTests;
	TestList*	m_Tests;
public:
	std::string m_Name;

	TestGroup(std::string name);
	~TestGroup();

	void RunAllTests();

	void AddTest(Test* test);

	int GetTestCount() const;

	inline int GetFailedTests() { return m_FailedTests;	}

private:
	void CleanUp();
};

class Test {
public:
	virtual ~Test();
protected:
	Test();
public:
	virtual void TestBody() = 0;
};

class AirTester {
private:
	GroupList*	m_Groups;

	AirTester();
	~AirTester();
public:
	void RunAll();

	TestGroup* GetTestGroup(std::string name);

	static AirTester* GetInstance();

private:
	TestGroup* AddTestGroup(TestGroup* testGroup);
};

template<class Type>
Test* RegisterTest(std::string groupName) {
	Test* test = new Type;
	AirTester::GetInstance()->GetTestGroup(groupName)->AddTest(test);
	return test;
}

#define TEST_CLASS_NAME(group, unit) test_##group##_unit

#define TEST(group, unit) \
class TEST_CLASS_NAME(group, unit) : public Test {\
private:\
	static Test const *test_executor;\
public:\
	TEST_CLASS_NAME(group, unit)() = default;\
	void TestBody() override;\
};\
Test const *TEST_CLASS_NAME(group, unit)::test_executor = RegisterTest<TEST_CLASS_NAME(group, unit)>(#group);\
void TEST_CLASS_NAME(group, unit)::TestBody()