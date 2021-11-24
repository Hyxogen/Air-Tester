#include <AirTester.h>
#include <iostream>

TEST(simple_tests, test1) {
	std::cout << "Hallo!" << std::endl;
}

int main(int argc, char** argv) {
	TEST_CLASS_NAME(simple_tests, test1) test;
	test.TestBody();
	return 0;
}