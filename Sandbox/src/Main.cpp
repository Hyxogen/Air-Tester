#include <AirTester.h>
#include <iostream>

TEST(simple_tests, test1) {
	std::cout << "Hallo!" << std::endl;
}

int main(int argc, char** argv) {
	AirTester::GetInstance()->RunAll();
	return 0;
}