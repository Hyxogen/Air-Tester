#include "AirTester.h"
#include <iostream>

TEST(simple_tests, equal) {
	std::cout << "Test!" << std::endl;
	EXPECT_TRUE(true == true);
	EXPECT_TRUE(false == true);
	EXPECT_FALSE(false == false);
	EXPECT_FALSE(true == false);
	EXPECT_EQUAL(5, 6);
	EXPECT_EQUAL(5, 5);
	EXPECT_NO_C_LEAK()
}

TEST(simple_tests, other) {
	std::cout << "Other!" << std::endl;
}


int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	RUN_ALL_TESTS();
//	AIR_RUN_ALL_TESTS_();
//	AIRTEST_TEST_CLASS_NAME(simple_tests, equal) test;
//	test.TestBody();
	return 0;
}