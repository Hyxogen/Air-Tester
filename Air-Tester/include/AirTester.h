#pragma once

#include <vector>
#include <string>
#include <iterator>

class Test;
class TestGroup;

typedef std::vector<Test*> TestList;
typedef std::vector<TestGroup*> GroupList;

class TestGroup {
protected:
	int			m_FailedTests;
private:
	TestList*	m_Tests;
public:
	const std::string m_Name;

	TestGroup(std::string name);
	~TestGroup();

	void RunAllTests();

	void AddTest(Test* test);

	int GetTestCount() const;

	inline int GetFailedTests() { return m_FailedTests;	}

	TestList::iterator begin() { return m_Tests->begin(); }
	TestList::iterator end() { return m_Tests->end(); }
private:
	void CleanUp();
};

class Test {
protected:
	int m_Failed = 0;

	Test();
public:
	virtual ~Test();

	virtual void TestBody() = 0;

	virtual std::string GetName() = 0;

	inline int GetFailedCount() { return m_Failed; }
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

#define TEST_CLASS_NAME(group, unit) test_##group##_##unit

#define TEST(group, unit) \
class TEST_CLASS_NAME(group, unit) : public Test {\
private:\
	static Test const *test_executor;\
public:\
	TEST_CLASS_NAME(group, unit)() = default;\
	void TestBody() override;\
	std::string GetName() override;\
};\
std::string TEST_CLASS_NAME(group, unit)::GetName() { return #unit; }\
Test const *TEST_CLASS_NAME(group, unit)::test_executor = RegisterTest<TEST_CLASS_NAME(group, unit)>(#group);\
void TEST_CLASS_NAME(group, unit)::TestBody()