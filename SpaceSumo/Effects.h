#pragma once

class RenderList;
class EffectStatus;

#include <vector>
#include "EffectStatus.h"


class Effects
{
public:
	Effects();
	~Effects();

	void draw(RenderList& renderList, SpaceManImp* owner);
	void update(sf::Keyboard::Key& push, GameData& data);
	void addEffect(EffectImp*);
	void clear();
	
	EffectStatus& getStatus();

private:
	EffectImp** mEffectList;
	EffectStatus mSummary;
	static const int MAX_SIZE;
	int mCurSize;

	void evaluate();
	void floatDown(int index);
};

