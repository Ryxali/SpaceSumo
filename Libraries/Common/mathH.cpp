#include "stdafx.h"
#include "mathH.h"
#include "SVector.h"
#include <cmath>


//sinus
template <>
float math::sin<float>(float val)
{
	return sinf(val);
}

template <>
double math::sin<double>(double val)
{
	return sin(val);
}

template <>
long double math::sin<long double>(long double val)
{
	return sinl(val);
}


//cosinus
template <>
float math::cos<float>(float val)
{
	return cosf(val);
}

template <>
double math::cos<double>(double val)
{
	return cos(val);
}

template <>
long double math::cos<long double>(long double val)
{
	return cosl(val);
}

// squareroot
template <>
float math::sqrt<float>(float val)
{
	return sqrtf(val);
}

template <>
double math::sqrt<double>(double val)
{
	return sqrt(val);
}

template <>
long double math::sqrt<long double>(long double val)
{
	return sqrtl(val);
}

