#pragma once

#include <vector>

class Test {
protected:
	Test();
public:
	virtual void TestBody() = 0;
};

class AirTester {
private:
	std::vector<Test*>* m_Tests;

	AirTester();
	~AirTester();
public:
	void RunAll();

	Test* AddTest(Test* test);

	static AirTester* GetInstance();
};

template<class Type>
Test* RegisterTest() {
	return AirTester::GetInstance()->AddTest(new Type);
}

#define TEST_CLASS_NAME(group, unit) test_##group##_unit

#define TEST(group, unit) \
class TEST_CLASS_NAME(group, unit) : public Test {\
private:\
	static Test const *test_executor;\
public:\
	TEST_CLASS_NAME(group, unit)() = default;\
\
	void TestBody() override;\
};\
Test const *TEST_CLASS_NAME(group, unit)::test_executor = RegisterTest<TEST_CLASS_NAME(group, unit)>();\
void TEST_CLASS_NAME(group, unit)::TestBody()