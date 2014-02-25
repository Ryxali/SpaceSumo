#pragma once

struct GameData;

class Playable
{
public:
	Playable(){}
	virtual ~Playable();

	virtual bool isPlaying() = 0;
	virtual bool hasEnded() = 0;
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual void setDestroy(bool) = 0;
	virtual bool getDestroy() = 0;
	virtual void update(GameData&) = 0;
};
