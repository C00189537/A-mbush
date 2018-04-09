#pragma once
#include "Entity.h"

class Enemy : public Entity 
{
public:

	Enemy() {}
	Enemy(Vector pos, int width, int height, SDL_Color colour, int speed);

	void update(float deltaTime);

private:

	int m_speed;
};