#include <iostream>
#include <string>
#include <typeinfo>

template<class Type, typename NextType>
struct TestNode {
	using Test = Type;
	using Next = NextType;
};

struct EndNode;

template<typename List, class Test>
struct PushBack;

template<class Next>
struct PushBackLast {
	using type = TestNode<Next, EndNode>;
};

template<class Current, typename Next, class Test>
struct PushBack<TestNode<Current, Next>, Test> {
	using staticList = TestNode<Current, typename PushBack<Next, Test>::staticList>;
};

template<class Current, class Next>
struct PushBack<TestNode<Current, EndNode>, Next> {
	using staticList = TestNode<Current, typename PushBackLast<Next>::type>;
};

template<typename List, template<typename T> class Function>
struct ForEach;

template<typename Current, typename Next, template<typename T> class Function>
struct ForEach<TestNode<Current, Next>, Function> {
	void operator()() {
		Function<Current>()();
		ForEach<Next, Function>()();
	}
};

template<typename Current, template<typename T> class Function>
struct ForEach<TestNode<Current, EndNode>, Function> {
	void operator()() {
		Function<Current>()();
	}
};

template<typename Type>
struct Function {
	void operator()() {
		std::cout << "Elements!" << typeid(Type).name() << std::endl;
	}
};

struct Empty {
};
struct NotEmpty {
};

struct TestClass {
};

typedef TestNode<Empty, EndNode> list;
typedef PushBack<list, TestClass>::staticList node1;
//typedef PushBack<list, NotEmpty>::staticList node2;
//typedef PushBack<list, TestClass>::staticList node3;

int main(int argc, char **argv) {
	ForEach<node1, Function>()();
//	Function<GetLast<node2>::value_type>()();
//	Function<PushFront<node2, TestClass>::type>()();
}