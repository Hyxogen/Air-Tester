#pragma once

#include "internal/InternalAirTester.hpp"

#define EXPECT_TRUE(condition) AIR_EXPECT_TRUE(condition, __FILE__, __LINE__)
#define EXPECT_FALSE(condition) AIR_EXPECT_FALSE(condition, __FILE__, __LINE__)

#define ASSERT_TRUE(condition) AIR_ASSERT_TRUE(condition, __FILE__, __LINE__)
#define ASSERT_FALSE(condition) AIR_ASSERT_FALSE(condition, __FILE__, __LINE__)

#define AIR_EXPECT_TRUE(condition, file, line) AIR_TEST_BOOLEAN_(condition, #condition, true, false, AIR_NONFATAL_FAIL, file, line);
#define AIR_EXPECT_FALSE(condition, file, line) AIR_TEST_BOOLEAN_(condition, #condition, false, true, AIR_NONFATAL_FAIL, file, line);

#define AIR_ASSERT_TRUE(condition, file, line) AIR_TEST_BOOLEAN_(condition, #condition, true, false, AIR_FATAL_FAIL, file, line);
#define AIR_ASSERT_FALSE(condition, file, line) AIR_TEST_BOOLEAN_(condition, #condition, false, true, AIR_FATAL_FAIL, file, line);

#define TEST(group, unit) AIR_TEST_(group, unit)