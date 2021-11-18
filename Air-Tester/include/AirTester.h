#ifndef AIRTESTER_H
#define AIRTESTER_H
#include "../src/internal/Test.hpp"
#include "internal/InternalAirTester.hpp"

extern "C" {
#include "../src/internal/utils/mem_utils.h"
};

#define AIR_NONFATAL_FAIL(message) \
	std::cout << "Message: " << message << std::endl;\
	m_FailedTests += 1;

#define TEST(group, test) AIR_TEST(group, test)

#define RUN_ALL_TESTS() AIR_RUN_ALL_TESTS()

#define EXPECT_TRUE(condition) AIR_EXPECT_TRUE(condition, __FILE__, __LINE__)
#define EXPECT_FALSE(condition) AIR_EXPECT_FALSE(condition, __FILE__, __LINE__)

#define EXPECT_EQUAL(val1, val2) AIR_EXPECT_EQUAL(val1, val2, __FILE__, __LINE__)
#define EXPECT_NOT_EQUAL(val1, val2) AIR_EXPECT_NOT_EQUAL(val1, val2, __FILE__, __LINE)

#define EXPECT_NO_C_LEAK(function) AIR_EXPECT_NO_C_LEAK(function, __FILE__, __LINE__)
//#define EXPECT_C_LEAK(function) AIR_EXPECT_C_LEAK(function, __FILE__, __LINE__)

#define AIR_TEST(group, test) AIR_TEST_(group, test, Test)

#define AIR_RUN_ALL_TESTS() AIR_RUN_ALL_TESTS_()

#define AIR_EXPECT_TRUE(condition, file, line) AIR_TEST_BOOL(condition, #condition, false, true, AIR_NONFATAL_FAIL, file, line)
#define AIR_EXPECT_FALSE(condition, file, line) AIR_TEST_BOOL(condition, #condition, true, false, AIR_NONFATAL_FAIL, file, line)

#define AIR_EXPECT_EQUAL(val1, val2, file, line) AIR_TEST_EQUAL(val1, #val1, val2, #val2, AIR_NONFATAL_FAIL, file, line)
#define AIR_EXPECT_NOT_EQUAL(val1, val2, file, line) AIR_TEST_NOT_EQUAL(val1, #val1, val2, #val2, AIR_NONFATAL_FAIL, file, line)

#define AIR_EXPECT_NO_C_LEAK(function, file, line) AIR_TEST_UNFREED_MEM(function, #function, get_unfreed_bytes(), 0, AIR_NONFATAL_FAIL, file, line)
//#define AIR_EXPECT_C_LEAK(function, file, line) AIR_TEST_UNFREED_MEM(function, #function, 0, AIR_NONFATAL_FAIL, file, line)

#endif //AIRTESTER_H