#include <iostream>
#include <string>
#include <typeinfo>

#define MAX_TESTS 10

template<int val>
struct Rank : Rank<val - 1> {

};

template<>
struct Rank<0> {

};

template<class... Tests>
struct TestList {
	static const int size = sizeof...(Tests);
};

template<class Test, typename List>
struct Append;

template<class Test, class... List>
struct Append<Test, TestList<List...>> {
	using value_type = TestList<Test, List...>;
};

TestList<> GetTests(Rank<0>) { return {}; }

#define GET_REGISTERED_TESTS													\
	decltype(GetTests(Rank<MAX_TESTS>()))

#define REGISTER_TEST(test)														\
	inline Append<Test1, GET_REGISTERED_TESTS>::value_type						\
		GetTests(Rank<GET_REGISTERED_TESTS::size + 1>)							\
		{																		\
			return {};															\
		}



class Test1 {

};
REGISTER_TEST(Test1)

class Test2 {

};
REGISTER_TEST(Test2)

int main(int argc, char **argv) {
//	std::cout << typeid(GET_REGISTERED_TESTS).name() << std::endl;
	std::cout << GET_REGISTERED_TESTS::size << std::endl;
//	std::cout << std::endl;
}