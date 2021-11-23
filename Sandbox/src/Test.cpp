#include "AirTester.h"
#include <iostream>

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
	EXPECT_SAME_STDOUT(std::printf("b"), std::printf("a"));
	EXPECT_SAME_STDOUT(std::printf("a"), std::printf("a"));
	EXPECT_SAME_STDOUT(std::printf("c"), std::printf("a"));
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