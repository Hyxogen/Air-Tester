//
// Created by Daan Meijer on 11/11/21.
//

#ifndef TEST_H
#define TEST_H

class Test {

public:
	Test();

	virtual ~Test() = 0;

	virtual void TestBody() = 0;
};

#endif //TEST_H
