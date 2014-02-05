#ifndef SPACESUMO_COMMON_MATH_INCLUDED
#define SPACESUMO_COMMON_MATH_INCLUDED
#include <type_traits>
#include <cstdint>
#include <cassert>

namespace math
{
	// TODO add more functionality here
	// REMINDER put templated function at the bottom!

	int round(float val);

	//sinus
	template <typename Tval>
	/*
		Get the sinus of a value
		param: Tval - the value you need the sinus of
		returns: the sinus of that value
	*/
	Tval sin(Tval val);

	//cosinus
	template <typename Tval>
	/*
		Get the cosinus of a value
		param: Tval - the value you need the cosinus of
		returns: the cosinus of that value
	*/
	Tval cos(Tval val);

	//squareroot
	template <typename Tval>
	/*
		Get the squareroot of a value
		param: Tval - the value you need the squareroot of
		returns: the squareroot of that value
	*/
	Tval sqrt(Tval val);

	//smallest value
	template <typename Tval0, typename Tval1>
	/*
		Get the smallest of two values.
		param: Tval v0 - the first value
		param: Tval v1 - the second value
		returns: Tval - the smallest value of the two
		template: Tval - a value type that permits use of the '<' operator
		template: Tval_other - a value type that permits use of the '<' operator
		note; this class will throw an error should Tval and Tval_other not be the
		same type!
	*/
	auto min(Tval0 v0, Tval1 v1) -> decltype((v0 < v1) ? v0 : v1)
	{
		return (v0 < v1) ? v0 : v1;
	}

	//largest value
	template <typename Tval0, typename Tval1>
	/*
		Get the largest of two values.
		param: Tval v0 - the first value
		param: Tval v1 - the second value
		returns: Tval - the largest value of the two
		template: Tval - a value type that permits use of the '<' operator
	*/
	auto max(Tval0 v0, Tval1 v1) -> decltype((v0 < v1) ? v0 : v1)
	{
		return (v1 < v0) ? v0 : v1;
	}
};


#endif