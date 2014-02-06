#pragma once
#include "EntityImp.h"
#include "B2Body.h"
#include <string>
#include <Box2D\Box2D.h>

namespace entFac
{
	EntityImp* createSpaceMan(std::string conf, b2World& world,
		std::string bodyData, float x, float y);
};