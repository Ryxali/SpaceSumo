#pragma once
#include "Button.h"
#include <ResourceManager\SSprite.h>
#include <string>

class DescriptedButton : public Button
{
public:
	DescriptedButton(Button* button, std::string ref, int z = 4.f);
	~DescriptedButton();
	virtual int getMapX() const;
	virtual int getMapY() const;
	virtual void setMapX(int x);
	virtual void setMapY(int y);

	virtual void update(GameData &data);
	virtual void draw(RenderList &renderList);
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	virtual void execute(int playerNumber);
	
	virtual void alert(bool status = true);
private:
	SSprite mSprite;
	bool mShouldRender;
	Button* mButton;
};

