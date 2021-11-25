#include <AirTester.h>
#include <iostream>

TEST(simple_tests, test1) {
	EXPECT_TRUE(true);
	// std::cout << "Hallo!" << std::endl;
}

TEST(simple_tests, test2) {
	EXPECT_TRUE(false);
	// std::cout << "Hallo!" << std::endl;
}

int main(int argc, char** argv) {
	AirTester::GetInstance()->RunAll();
	return 0;
}