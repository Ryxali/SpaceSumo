#pragma once
#include <string>
#include <ResourceManager\Animation.h>
#include <SFML\System\Vector2.hpp>

class RenderList;

class Face
{
public:
	enum Mood
	{
		IDLE, PLEASED, ANGRY, ASHAMED
	};
	//static const unsigned char IDLE;
	//static const unsigned char PLEASED;
	//static const unsigned char ANGRY;
	//static const unsigned char ASHAMED;

	Face(std::string faceImg);
	~Face();

	void changeMood(Mood mood);
	void draw(RenderList &list, const sf::Vector2f &pos, bool flipped);
private:
	Face(const Face& face);
	Face& operator=(const Face& face);
	Animation mFaces;
	
};

struct FacePool
{
	FacePool();
	Face test;
private:
	FacePool(const FacePool& fPool);
	FacePool& operator=(const FacePool& fPool);
};