#ifndef AIRTESTER_H
#define AIRTESTER_H
#include "internal/Test.h"
#include "internal/InternalAirTester.h"

#define TEST(group, test) AIR_TEST(group, test)

#define RUN_ALL_TESTS() AIR_RUN_ALL_TESTS()

#define AIR_TEST(group, test) AIR_TEST_(group, test, Test)

#define AIR_RUN_ALL_TESTS() AIR_RUN_ALL_TESTS_()

#endif //AIRTESTER_H
