#ifndef INTERNALAIRTESTER_H
#define INTERNALAIRTESTER_H
#include "Vector.h"

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

#endif //INTERNALAIRTESTER_H