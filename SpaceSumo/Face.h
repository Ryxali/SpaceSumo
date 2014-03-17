#pragma once
#include <string>
#include <ResourceManager\Animation.h>
#include <SFML\System\Vector2.hpp>

class RenderList;
enum Position;
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
	void draw(RenderList &list, const Position &pos, bool flipped);
	void setOrigin(int x, int y);
	void setPersona(std::string ref);
private:
	Face(const Face& face);
	Face& operator=(const Face& face);
	Animation mFaces;
	sf::Vector2f mOrigin;
};

