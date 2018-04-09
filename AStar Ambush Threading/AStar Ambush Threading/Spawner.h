#pragma once
#include "Enemy.h"
class Spawner
{
public:

	virtual Enemy* GreenEnemy(SDL_Point pos) = 0;
	virtual Enemy* BlueEnemy(SDL_Point pos) = 0;
	virtual Enemy* RedEnemy(SDL_Point pos) = 0;

private:

protected:
	Spawner() {};
	~Spawner() {};
};