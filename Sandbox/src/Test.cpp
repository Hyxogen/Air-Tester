#include "AirTester.h"
#include <iostream>
\

/**
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
	EXPECT_TRUE(true == true)
	EXPECT_TRUE(false == true)
	EXPECT_FALSE(false == false)
	EXPECT_FALSE(true == false)
	EXPECT_EQUAL(5, 6)
	EXPECT_EQUAL(5, 5)
	EXPECT_EQUAL("Abc", "Abc")
	EXPECT_EQUAL("Abc", "abc")
	EXPECT_NOT_EQUAL("Abc", "Abc")
	EXPECT_NOT_EQUAL("Abc", "abc")\
}

TEST(simple_tests, other) {
	std::cout << "Other!" << std::endl;
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	RUN_ALL_TESTS();
	return 0;
}