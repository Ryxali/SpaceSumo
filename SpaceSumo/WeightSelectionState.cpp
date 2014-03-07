#include "stdafx.h"
#include "WeightSelectionState.h"

#include "SetWeightClassCommand.h"
#include "ChangeStateCommand.h"
#include "DualCommand.h"
#include "PlayerReadyToggleCommand.h"

#include "StateList_CSelect.h"
#include "ButtonMulti.h"
#include"ButtonSelectionEffect.h"
#include <fstream>
#include <string>
#include "SpacemanData.h"

WeightSelectionState::WeightSelectionState(StateList &owner, SpacemanData (&mSpacemenData)[4])
	: State(owner), mWeightClasses(5), mOnFinish(new ChangeStateCommand(st::FINISHED_STATE, owner))
{
	for(int i = 0; i < 4; ++i)
	{
		mPlayerReadyStatus[i] = false;
	}
	std::string s;
	std::ifstream ifs("res/conf/characters/weight_classes.xoxo");
	int x = 0;
	while(std::getline(ifs, s))
	{
		mWeightClasses.add(new ButtonMulti(
			SVector(x*200, 300),
			x,
			0,
			new DualCommand(
				new SetWeightClassCommand(
					mSpacemenData[0], s+"_Body.cfg", s+"_Hands.cfg"),
				new PlayerReadyToggleCommand(mPlayerReadyStatus[0])),
			new DualCommand(
				new SetWeightClassCommand(
					mSpacemenData[1], s+"_Body.cfg", s+"_Hands.cfg"),
				new PlayerReadyToggleCommand(mPlayerReadyStatus[1])),
			new DualCommand(
				new SetWeightClassCommand(
					mSpacemenData[2], s+"_Body.cfg", s+"_Hands.cfg"),
				new PlayerReadyToggleCommand(mPlayerReadyStatus[2])),
			new DualCommand(
				new SetWeightClassCommand(
					mSpacemenData[3], s+"_Body.cfg", s+"_Hands.cfg"),
				new PlayerReadyToggleCommand(mPlayerReadyStatus[3])),
			("res/img/UI/menu/weightSelection/weight_class_" + std::to_string(x))));
		++x;
	}
	mWeightClasses.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_1, mWeightClasses.getFirst()));
	mWeightClasses.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_2, mWeightClasses.getFirst()));
	mWeightClasses.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_3, mWeightClasses.getFirst()));
	mWeightClasses.addObserver(new ButtonSelectionEffect(ControlList::PLAYER_4, mWeightClasses.getFirst()));
}

void WeightSelectionState::draw(RenderList &list)
{
	mWeightClasses.draw(list);
}

void WeightSelectionState::update(GameData &data, int delta)
{
	mWeightClasses.update(data, delta);
	if(mPlayerReadyStatus[0] && mPlayerReadyStatus[1] && mPlayerReadyStatus[2] && mPlayerReadyStatus[3])
		mOwner.changeState(st::FINISHED_STATE);
}

WeightSelectionState::~WeightSelectionState()
{
}
