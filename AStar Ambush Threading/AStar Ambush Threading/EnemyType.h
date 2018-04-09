#pragma once
#include "Spawner.h"
#include <string>

class EnemyType : public Spawner
{
public:
	EnemyType() {};
	~EnemyType() {};
	Enemy* GreenEnemy(SDL_Point pos);
	Enemy* BlueEnemy(SDL_Point pos);
	Enemy* RedEnemy(SDL_Point pos);
private:

	Enemy * enemyType;
};

