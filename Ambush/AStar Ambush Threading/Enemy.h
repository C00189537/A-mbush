#pragma once
#include "Entity.h"

class Enemy : public Entity 
{
public:

	Enemy() {}
	Enemy(SDL_Point pos, SDL_Rect r, SDL_Color colour, int speed);

	void update(float deltaTime);

private:

	int m_speed;
};