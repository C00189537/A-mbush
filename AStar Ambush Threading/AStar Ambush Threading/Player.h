#pragma once

#include "Entity.h"
#include "Keys.h"

class Player : public Entity 
{
public:

	Player() {}
	Player(SDL_Point pos, SDL_Rect r, SDL_Color colour, Keys *listener);

	void update(float deltaTime);

private:
	//Handles input
	Keys *m_keys;
	void inputHandle(float deltaTime);
	int m_speed;
};