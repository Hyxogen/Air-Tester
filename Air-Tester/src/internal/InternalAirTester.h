#ifndef INTERNALAIRTESTER_H
#define INTERNALAIRTESTER_H

template<class Test, typename Next>
struct TestNode {
	using Test = test;
	using Next = next;
};

struct EndNode;

template<typename List, class Test>
struct PushBack;

template<class Next>
struct PushBackLast {
	using type = TestNode<Next, End>;
};

template<class Current, typename Next, class Test>
struct PushBack<TestNode<Current, Next>> {
	using staticList = TestNode<Current, typename PushBack<Next, test>::staticList>;
};

template<class Current, class Next, class Test>
struct PushBack<TestNode<Current, EndNode>> {
	using staticList = TestNode<Current, typename PushBackLast<Next>::type>;
};


#define AIRTEST_TEST_CLASS_NAME(group, test) group##_##test##_test

#define AIRTEST_TEST_(group, test, parent)										\
class AIRTEST_TEST_CLASS_NAME(group, test) : public parent {					\
public:																			\
        AIRTEST_TEST_CLASS_NAME(group, test)() = default;						\
        ~AIRTEST_TEST_CLASS_NAME(group, test)() = default;						\
        																		\
        void TestBody() override;												\
};																				\
void AIRTEST_TEST_CLASS_NAME(group, test)::TestBody()
#endif //INTERNALAIRTESTER_H