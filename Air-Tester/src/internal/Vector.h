//
// Created by Daan Meijer on 11/17/21.
//

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

Vector<> GetTypes(Rank<0>) { return {}; }

#define GET_VECTOR_TYPES()														\
	decltype(GetTypes(Rank<VECTOR_MAX_ELEMENTS>()))

#define ADD_VECTOR_ELEMENT(element)												\
	inline Append<element, GET_VECTOR_TYPES()>::type_value						\
		GetTypes(Rank<GET_VECTOR_TYPES()::size + 1>) {							\
			return {};															\
		}

#endif //VECTOR_H