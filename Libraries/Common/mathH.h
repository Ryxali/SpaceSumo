#ifndef SPACESUMO_COMMON_MATH_INCLUDED
#define SPACESUMO_COMMON_MATH_INCLUDED
#include <type_traits>
#include <cstdint>
#include <cassert>

namespace math
{
	// TODO add more functionality here
	// REMINDER put templated function at the bottom!




	
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