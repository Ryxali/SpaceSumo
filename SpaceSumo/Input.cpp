#include "stdafx.h"
#include "Input.h"


Input::Input() : mEvts(), mSize(0), mIterations(0)
{
}


Input::~Input()
{
}

void Input::add(sf::Event &evt)
{
	mEvts.push(evt);//.push_back(evt);
	mSize++;
}

bool Input::pop_front(sf::Event &evt)
{
	if(mEvts.empty() || mSize == mIterations)
	{
		mIterations = 0;
		return false;
	}
	evt = mEvts.front();
	mEvts.pop();
	mSize--;
	mIterations++;
	return true;
}

void Input::clear()
{
	while(!mEvts.empty())
		mEvts.pop();
}