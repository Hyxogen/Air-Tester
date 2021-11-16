#include <iostream>
#include <string>

template<typename Current, typename Next>
struct Node {
	typedef Current current;
	typedef Next next;
};

struct End;

template<typename List, typename Type>
struct PushBack {
	typedef Node<Type, List> staticList;
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
		std::cout << "Elements!" << std::endl;
	}
};

struct Empty;

typedef PushBack<End, Empty>::staticList node1;
typedef PushBack<node1, Empty>::staticList node2;

int main(int argc, char **argv) {
	ForEach<node2, Function>()();
}