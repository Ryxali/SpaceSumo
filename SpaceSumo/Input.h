#pragma once
#include <queue>
#include <SFML\Window\Event.hpp>

class Input
{
public:
	Input();
	~Input();
	void add(sf::Event &evt);
	/*
		Get the event at the front of the queue
		param: sf::Event &evt - The event to pop into
		returns: bool - Whether we've run out of events to pop
	*/
	bool pop_front(sf::Event &evt);
	void clear();
private:
	Input(const Input& input);
	Input& operator=(const Input& input);
	std::queue<sf::Event> mEvts;
	short mSize;
	short mIterations;
};

