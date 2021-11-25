#include <AirTester.h>
#include <iostream>

TEST(other_tests, test_other) {
	EXPECT_TRUE(false);
	EXPECT_TRUE(!true);
	EXPECT_TRUE(!!false);
	EXPECT_TRUE(!!!!!false);
	EXPECT_TRUE(false);
	// std::cout << "This is another test!" << std::endl;
}