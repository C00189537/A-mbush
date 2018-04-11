#pragma once

#include "Entity.h"
#include "Keys.h"

class Player : public Entity 
{
public:

	Player() {}
	Player(SDL_Point pos, SDL_Rect r, SDL_Color colour, Keys *listener);

	void update(float deltaTime);
	void setVelocity(SDL_Point v);
	SDL_Point getVelocity();

private:
	//Handles input
	Keys *m_keys;
	void inputHandle(float deltaTime);
	void friction();
	int m_speed;
	SDL_Point m_velocity;
	int MAX_XVEL = 2, MAX_YVEL = 2;
};