#ifndef INTERNALAIRTESTER_H
#define INTERNALAIRTESTER_H
#include <iostream>
#include <unistd.h>
#include "Vector.hpp"
#include "Assert.h"

extern "C" {
#include "../../src/internal/utils/mem_utils.h"
};

#define AIR_TEST_CLASS_NAME(group, test) group##_##test##_test
#define AIR_TEST_CLASS_NAME_STR(group, test) #group "_" #test "_test"

#ifndef AIR_READ_BUFFER_SIZE
#define AIR_READ_BUFFER_SIZE 4069
#endif

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
bool IsEqual(char* str1, char* str2) {
	return (!strcmp(str1, str2));
}

template<>
bool IsEqual(const char* str1, char* str2) {
	return (!strcmp(str1, str2));
}

template<>
bool IsEqual(char* str1, const char* str2) {
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
//AIR_TEST_FD_OUTPUT_(func1, func2, 1, 1, true, AIR_NONFATAL_FAIL, file, line)
//Wil ik de definitie hier houden?
//De definitie moet echt weg hier, niet platform neutral
#define AIR_TEST_FD_OUT_(func1, func2, func1_fd, func2_fd, equal, fail, file, line) \
	{                                                                                   \
    	int func1_fd_cpy, func2_fd_cpy;                                                \
    	int pipe_vals[2];                                                               \
        char eof;                                                                            \
    	char func1_buffer[AIR_READ_BUFFER_SIZE];                                        \
    	char func2_buffer[AIR_READ_BUFFER_SIZE];                                        \
    	ssize_t func1_read;                                                             \
    	ssize_t func2_read;\
                                                                                     \
    	func1_fd_cpy = dup(1);                                                                \
    	func2_fd_cpy = dup(2);                                                                \
                                                                                    \
        setbuf(stdout, 0);                                                          \
        setbuf(stderr, 0);\
                                                                                    \
        eof = EOF;                                                                             \
        ASSERT(pipe(pipe_vals) != -1);                                                     \
        ASSERT(dup2(pipe_vals[1], func1_fd) != -1);                                                \
        func1;                                                                             \
        write(func1_fd, &eof, 1);                                                                            \
        ASSERT((func1_read = read(pipe_vals[0], &func1_buffer[0], AIR_READ_BUFFER_SIZE)) > 0);\
        func1_buffer[func1_read - 1] = '\0';                                             \
        ASSERT(dup2(pipe_vals[1], func2_fd) != -1);                                  \
        func2;\
        write(func1_fd, &eof, 1);                                                                            \
        ASSERT((func2_read = read(pipe_vals[0], &func2_buffer[0], AIR_READ_BUFFER_SIZE)) > 0);\
    	func2_buffer[func2_read - 1] = '\0';                                                \
    	ASSERT(dup2(func1_fd_cpy, func1_fd) != -1);\
    	ASSERT(dup2(func2_fd_cpy, func2_fd) != -1);\
    	close(pipe_vals[0]);                                                            \
    	close(pipe_vals[1]);                                                            \
    	if (IsEqual(&func1_buffer[0], &func2_buffer[0]) == equal)                                \
    		;                                                                              \
    	else {                                                                          \
        	fail("Failed tests. Expected: \"" << &func1_buffer[0] << "\" (" #func1 ") got: \"" << &func2_buffer[0] << "\" (" #func2 ") file:" #file " line:" #line)                                                                            \
    	}\
	}
#endif //INTERNALAIRTESTER_H