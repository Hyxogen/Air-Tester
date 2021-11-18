#include "AirTester.h"
#include <iostream>

//#define AIR_TRACK_MEMORY

extern "C" {
#include "mem_leak.h"
}

/**
 * Todo AIR TESTER
 *  - Track how many bytes leaked
 *  - Print which test failed
 * Todo ft_printf
 * - Add tests for char specifier
 * - fully implement char specifier
 * - Add tests for string specifier
 * - fully implement string specifier
 * - Add tests for signed int specifier
 * - fully implement signed int specifier
 */

TEST(simple_tests, equal) {
	std::cout << "Test!" << std::endl;
	EXPECT_TRUE(true == true);
	EXPECT_TRUE(false == true);
	EXPECT_FALSE(false == false);
	EXPECT_FALSE(true == false);
	EXPECT_EQUAL(5, 6);
	EXPECT_EQUAL(5, 5);
	EXPECT_EQUAL("Abc", "Abc");
	EXPECT_EQUAL("Abc", "abc");
	EXPECT_NO_C_LEAK(function_that_leaks())
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