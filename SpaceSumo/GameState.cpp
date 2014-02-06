#include "GameState.h";
#include "stdafx.h";


void GameState::draw(list){
	
	for(std::vector<Entity>::iterator it=EntityList.begin(); it!=EntityList.end(); it++){
		(*it).draw(list);
	}
	
}

void GameState::spacemanCreation(){
	for(int i=0; i<4; i++){
		EntityList.push_back(enFac::createSpaceman());
	}
}