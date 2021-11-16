#include <iostream>
#include <string>
#include <typeinfo>

template<class Current, typename Next>
struct Node {
	typedef Current current;
	typedef Next next;
};

struct End;




template<typename List, class Current>
struct PushBack {
	typedef Node<Current, List> staticList;
};

template<typename List, class Element>
struct PushFront;

template<typename New>
struct PushFrontLast {
	using staticList = Node<New, End>;
//	typedef Node<New, End> staticList;
};

template<class Element, class New>
struct PushFront<Node<Element, End>, New> {
	using type = Node<Element, typename PushFrontLast<New>::staticList>;
};

template<class Current, class New, typename Next>
struct PushFront<Node<Current, Next>, New> {
	using type = Node<Current, PushFront<Next, New>>;
};




template<typename List, template<typename T> class Function>
struct ForEach;

template<typename Current, typename Next, template<typename T> class Function>
struct ForEach<Node<Current, Next>, Function> {
	void operator()() {
		Function<Current>()();
		ForEach<Next, Function>()();
	}
};

template<typename Current, template<typename T> class Function>
struct ForEach<Node<Current, End>, Function> {
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

template<typename Element>
struct GetLast;

template<class Value, typename Next>
struct GetLast<Node<Value, Next>> {
	using value_type = typename GetLast<Next>::value_type;
};

template<class Value>
struct GetLast<Node<Value, End>> {
	using value_type = Value;
};

typedef PushBack<End, Empty>::staticList node1;
typedef PushBack<node1, NotEmpty>::staticList node2;

int main(int argc, char **argv) {
//	ForEach<node2, Function>()();
//	Function<GetLast<node2>::value_type>()();
	Function<PushFront<node2, TestClass>::type>()();
}