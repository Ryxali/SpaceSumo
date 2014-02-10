#include "stdafx.h"
#include "mathH.h"
#include <cmath>


int math::round(float val)
{
	int r = (int) val;
	val -= (float)r;
	if(val < 0.5)
		  return r;
	return r++;
}

//sinus
template <>
float math::sin<float>(float val)
{
	return std::sinf(val);
}

template <>
double math::sin<double>(double val)
{
	return std::sin(val);
}

template <>
long double math::sin<long double>(long double val)
{
	return std::sinl(val);
}


//cosinus
template <>
float math::cos<float>(float val)
{
	return std::cosf(val);
}

template <>
double math::cos<double>(double val)
{
	return std::cos(val);
}

template <>
long double math::cos<long double>(long double val)
{
	return std::cosl(val);
}

// squareroot
template <>
float math::sqrt<float>(float val)
{
	return std::sqrtf(val);
}

template <>
double math::sqrt<double>(double val)
{
	return std::sqrt(val);
}

template <>
long double math::sqrt<long double>(long double val)
{
	return std::sqrtl(val);
}

