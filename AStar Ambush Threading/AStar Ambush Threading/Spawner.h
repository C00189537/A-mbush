#pragma once
#include "Enemy.h"
class Spawner
{
public:

	virtual Enemy* GreenEnemy(Vector pos) = 0;
	virtual Enemy* BlueEnemy(Vector pos) = 0;
	virtual Enemy* RedEnemy(Vector pos) = 0;

private:

protected:
	Spawner() {};
	~Spawner() {};
};