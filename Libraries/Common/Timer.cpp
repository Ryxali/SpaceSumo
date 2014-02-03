#include "stdafx.h"
#include "Timer.h"

sf::Clock Timer::mClock = sf::Clock();

Timer::Timer(int miliseconds) : mDuration(miliseconds), mStartTime(mClock.getElapsedTime().asMilliseconds())
{
}

Timer::~Timer()
{
}

bool Timer::isExpired()
{
	if(mClock.getElapsedTime().asMilliseconds() - mStartTime > mDuration)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Timer::reset()
{
	mStartTime = mClock.getElapsedTime().asMilliseconds();
}

void Timer::setDuration(int miliseconds)
{
	mDuration = miliseconds;
}