#ifndef INTERNALAIRTESTER_H
#define INTERNALAIRTESTER_H
#include <iostream>
#include "Vector.hpp"

extern "C" {
#include "../../src/internal/utils/mem_utils.h"
};

#define AIR_TEST_CLASS_NAME(group, test) group##_##test##_test
#define AIR_TEST_CLASS_NAME_STR(group, test) #group "_" #test "_test"

#define AIR_TEST_(group, test, parent)																						\
class AIR_TEST_CLASS_NAME(group, test) : public parent {																	\
public:																														\
        AIR_TEST_CLASS_NAME(group, test)() = default;																		\
        ~AIR_TEST_CLASS_NAME(group, test)() = default;																		\
        																													\
        void TestBody() override;																							\
        std::string GetTestName() override;																					\
};																															\
std::string AIR_TEST_CLASS_NAME(group, test)::GetTestName() { return std::string(AIR_TEST_CLASS_NAME_STR(group, test)); }	\
ADD_VECTOR_ELEMENT(AIR_TEST_CLASS_NAME(group, test))																		\
void AIR_TEST_CLASS_NAME(group, test)::TestBody()

template<class Type>
struct ExecuteTest {
	void operator()() {
		Type().Execute();
	}
};

template<typename LHS, typename RHS>
bool IsEqual(LHS lhs, RHS rhs) {
	return lhs == rhs;
}

template<>
bool IsEqual(const char* str1, const char* str2) {
	return (!strcmp(str1, str2));
}

template<>
bool IsEqual(unsigned long lhs, int rhs) {
	return ((rhs >= 0) && ((unsigned long) rhs == lhs));
}

template<>
bool IsEqual(int lhs, unsigned long rhs) {
	return ((lhs >= 0) && ((unsigned long) lhs == rhs));
}

#define AIR_RUN_ALL_TESTS_() ForEach<ExecuteTest, GET_VECTOR_TYPES()>()()

#define AIR_TEST_UNFREED_MEM(function, function_str, actual, expected, fail, file, line) \
    clear_tracked_memory();                                                  \
    function;                                                                          \
	if (IsEqual(actual, expected))                                             \
		;\
	else {\
        fail("Failed test. Expected " #expected " bytes of unfreed memory. Actual " << actual << " bytes") \
    }

#define AIR_TEST_EQUAL(val1, val1_str, val2, val2_str, fail, file, line) \
	if (IsEqual(val1, val2)) \
		; \
	else {\
        fail("Failed test. Expected: " #val1 "(" #val1_str ") to be equal to: " #val2 "(" #val2_str "). Actual: is not equal") \
    }

#define AIR_TEST_NOT_EQUAL(val1, val1_str, val2, val2_str, fail, file, line) \
	if (!IsEqual(val1, val2)) \
		; \
	else {\
        fail("Failed test. Expected: " #val1 "(" #val1_str ") to be not equal to: " #val2 "(" #val2_str "). Actual: is equal") \
    }

#define AIR_TEST_BOOL(condition, condition_str, actual, expected, fail, file, line) \
	if (condition == expected) \
		; \
	else {\
        fail("Failed test. Expected: " #expected " got: " #actual " for condition: " #condition_str " file:" #file " line:" #line)\
    }
#endif //INTERNALAIRTESTER_H