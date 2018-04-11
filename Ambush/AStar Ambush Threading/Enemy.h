#pragma once
#include "Entity.h"
#include "Node.h"


class Enemy : public Entity 
{
public:

	Enemy() {}
	Enemy(SDL_Point pos, SDL_Rect r, SDL_Color colour, int speed);
	void update(float deltaTime);
	std::vector<Node*> nodePath;

private:
	int m_speed;

};