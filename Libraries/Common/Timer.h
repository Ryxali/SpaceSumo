#ifndef SPACESUMO_COMMON_TIMER_INCLUDED
#define SPACESUMO_COMMON_TIMER_INCLUDED

#include <SFML\System\Clock.hpp>

class Timer
{
public:
	Timer(int miliseconds);
	~Timer();

	bool isExpired();
	void reset();
	void setDuration(int miliseconds);

private:
	static sf::Clock mClock;
	int mDuration;
	int mStartTime;
};

#endif