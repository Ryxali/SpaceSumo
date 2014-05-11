#pragma once

class RenderList;
class EffectStatus;
class Controller;
class Link;
#include <vector>
#include "EffectStatus.h"


class Effects
{
public:
	Effects();
	~Effects();

	void draw(RenderList& renderList, SpaceManImp* owner);
	void update(Controller& pController, GameData& data);
	void addEffect(EffectImp*);
	void clear();
	
	EffectStatus& getStatus();

private:
	Link *mFirstEffect;
	EffectImp** mEffectList;
	EffectStatus mSummary;
	static const int MAX_SIZE;
	int mCurSize;

	void evaluate();
	void floatDown(int index);
};

