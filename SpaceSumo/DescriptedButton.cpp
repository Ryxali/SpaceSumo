#include "stdafx.h"
#include "DescriptedButton.h"
#include <ResourceManager\RHandle.h>
#include <Common\Config.h>
#include "RenderList.h"

DescriptedButton::DescriptedButton(Button* button, std::string ref, int z) : mButton(button), mSprite(res::getTexture(ref+".png"), z), mShouldRender(false)
{
	Config cfg(ref+".cfg");
	mSprite.getSprite().setPosition(cfg.getValue<int>("xPos"), cfg.getValue<int>("yPos"));
}


DescriptedButton::~DescriptedButton(void)
{
	delete mButton;
}

int DescriptedButton::getMapX() const
{
	return mButton->getMapX();
}

int DescriptedButton::getMapY() const
{
	return mButton->getMapY();
}
void DescriptedButton::setMapX(int x)
{
	mButton->setMapX(x);
}
void DescriptedButton::setMapY(int y)
{
	mButton->setMapY(y);
}

void DescriptedButton::update(GameData &data)
{
	mButton->update(data);
}

void DescriptedButton::draw(RenderList &renderList)
{
	if(mShouldRender)
		renderList.addSprite(mSprite);
	mButton->draw(renderList);
}

float DescriptedButton::getCenterX() const
{
	return mButton->getCenterX();
}

float DescriptedButton::getCenterY() const
{
	return mButton->getCenterY();
}

void DescriptedButton::execute(int playerNumber)
{
	mButton->execute(playerNumber);
}

void DescriptedButton::alert(bool status)
{
	mShouldRender = status;
}