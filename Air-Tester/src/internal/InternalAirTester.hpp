#ifndef INTERNALAIRTESTER_H
#define INTERNALAIRTESTER_H
#include <iostream>
#include "Vector.hpp"

extern "C" {
#include "utils/mem_utils.h"
};

#define AIR_NONFATAL_FAIL(message) \
	std::cout << message << std::endl;

#define AIR_TEST_CLASS_NAME(group, test) group##_##test##_test

#define AIR_TEST_(group, test, parent)											\
class AIR_TEST_CLASS_NAME(group, test) : public parent {						\
public:																			\
        AIR_TEST_CLASS_NAME(group, test)() = default;							\
        ~AIR_TEST_CLASS_NAME(group, test)() = default;							\
        																		\
        void TestBody() override;												\
};																				\
ADD_VECTOR_ELEMENT(AIR_TEST_CLASS_NAME(group, test))							\
void AIR_TEST_CLASS_NAME(group, test)::TestBody()

template<class Type>
struct ExecuteTest {
	void operator()() {
		Type().TestBody();
	}
};

#define AIR_RUN_ALL_TESTS_() ForEach<ExecuteTest, GET_VECTOR_TYPES()>()()

#define AIR_TEST_UNFREED_MEM(function, function_str, bytes, fail, file, line) \
    clear_tracked_memory();                                                  \
    function;                                                                          \
	if (get_unfreed_count() == bytes)                                             \
		;\
	else\
		fail("Failed test. Expected " #bytes " bytes of unfreed memory. Actual TO BE FILLED IN")

#define AIR_TEST_EQUAL(val1, val1_str, val2, val2_str, fail, file, line) \
	if (val1 == val2) \
		; \
	else \
		fail("Failed test. Expected: " #val1 "(" #val1_str ") to be equal to: " #val2 "(" #val2_str "). Actual: is not equal")
#define AIR_TEST_BOOL(condition, condition_str, actual, expected, fail, file, line) \
	if (condition == expected) \
		; \
	else \
		fail("Failed test. Expected: " #expected " got: " #actual " for condition: " #condition_str " file:" #file " line:" #line)
#endif //INTERNALAIRTESTER_H