//
// Created by Daan Meijer on 11/11/21.
//

#ifndef TEST_H
#define TEST_H

#include <string>

class Test {

protected:
	int m_FailedTests = 0;

public:
	Test();

	virtual ~Test() = 0;

	void Execute();

	virtual void TestBody() = 0;

	virtual std::string GetTestName() = 0;
};

#endif //TEST_H
