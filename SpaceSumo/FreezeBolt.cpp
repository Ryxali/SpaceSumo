#include "stdafx.h"
#include "FreezeBolt.h"


FreezeBolt::FreezeBolt(SVector pos, SVector speed) 
	: mPosition(pos), mSpeed(speed)
{
}

FreezeBolt::~FreezeBolt()
{
}

void FreezeBolt::update(int delta)
{
	float f = (float)delta / 1000;
	//TODO add f to force with speed
}

void FreezeBolt::draw(RenderList& renderList)
{
}

void FreezeBolt::addEffect()
{
}