#ifndef AIRTESTER_H
#define AIRTESTER_H
#include "internal/Test.h"
#include "internal/InternalAirTester.h"

#define TEST(group, test) AIR_TEST(group, test)

#define RUN_ALL_TESTS() AIR_RUN_ALL_TESTS()

#define EXPECT_TRUE(condition) AIR_EXPECT_TRUE(condition, __FILE__, __LINE__)
#define EXPECT_FALSE(condition) AIR_EXPECT_FALSE(condition, __FILE__, __LINE__)

#define EXPECT_EQUAL(val1, val2) AIR_EXPECT_EQUAL(val1, val2, __FILE__, __LINE__)

#define AIR_TEST(group, test) AIR_TEST_(group, test, Test)

#define AIR_RUN_ALL_TESTS() AIR_RUN_ALL_TESTS_()

#define AIR_EXPECT_TRUE(condition, file, line) AIR_TEST_BOOL(condition, #condition, false, true, AIR_NONFATAL_FAIL, file, line)
#define AIR_EXPECT_FALSE(condition, file, line) AIR_TEST_BOOL(condition, #condition, true, false, AIR_NONFATAL_FAIL, file, line)

#define AIR_EXPECT_EQUAL(val1, val2, file, line) AIR_TEST_EQUAL(val1, #val1, val2, #val2, AIR_NONFATAL_FAIL, file, line)

#endif //AIRTESTER_H
