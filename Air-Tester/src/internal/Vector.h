#ifndef VECTOR_H
#define VECTOR_H

#ifndef VECTOR_MAX_ELEMENTS
#define VECTOR_MAX_ELEMENTS 20
#endif

template<int rank>
struct Rank : Rank<rank - 1> {

};

template<>
struct Rank<0> {

};

template<typename... Element>
struct Vector {
	static const int size = sizeof...(Element);
};

template<typename New, typename List>
struct Append;

template<typename New, typename... Element>
struct Append<New, Vector<Element...>> {
	using type_value = Vector<Element..., New>;
};

template< template<typename Type> class Function, typename List>
struct ForEach;

template< template<typename Type> class Function, typename Current, typename... Remaining>
struct ForEach<Function, Vector<Current, Remaining...>> {
	void operator()() {
		Function<Current>()();
		ForEach<Function, Vector<Remaining...>>()();
	}
};

template<template<typename Type> class Function, typename Current>
struct ForEach<Function, Vector<Current>> {
	void operator()() {
		Function<Current>()();
	}
};

Vector<> GetTypes(Rank<0>) { return {}; }

#define GET_VECTOR_TYPES()														\
	decltype(GetTypes(Rank<VECTOR_MAX_ELEMENTS>()))

#define ADD_VECTOR_ELEMENT(element)												\
	inline Append<element, GET_VECTOR_TYPES()>::type_value						\
		GetTypes(Rank<GET_VECTOR_TYPES()::size + 1>) {							\
			return {};															\
		}

#endif //VECTOR_H