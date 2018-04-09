#pragma once
#include "Spawner.h"
#include <string>

class EnemyType : public Spawner
{
public:
	EnemyType() {};
	~EnemyType() {};
	Enemy* GreenEnemy(Vector pos);
	Enemy* BlueEnemy(Vector pos);
	Enemy* RedEnemy(Vector pos);
private:

	Enemy * enemyType;
};

