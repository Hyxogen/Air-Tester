//
// Created by Daan Meijer on 11/11/21.
//
#include "AirTester.h"
#include <iostream>

TEST(simple_tests, equal) {
	std::cout << "Test!" << std::endl;
}

TEST(simple_tests, other) {
	std::cout << "Other!" << std::endl;
}


int main(int argc, char **argv) {
	RUN_ALL_TESTS();
//	AIR_RUN_ALL_TESTS_();
//	AIRTEST_TEST_CLASS_NAME(simple_tests, equal) test;
//	test.TestBody();
	return 0;
}