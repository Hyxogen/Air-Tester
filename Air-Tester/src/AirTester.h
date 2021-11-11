#ifndef AIRTESTER_H
#define AIRTESTER_H
#include "internal/Test.h"
#include "internal/InternalAirTester.h"

#define TEST(group, test) AIR_TEST(group, test)

#define AIR_TEST(group, test) AIRTEST_TEST_(group, test, Test)

#define TEST(group, test) AIR_TEST(group, test)
#endif //AIRTESTER_H
