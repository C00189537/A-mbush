#include "EnemyType.h"

Enemy * EnemyType::GreenEnemy(SDL_Point pos)
{
	//Average green enemy
	enemyType = new Enemy(pos, {pos.x, pos.y, 20, 20 }, { 0, 255, 255 }, 100);
	return enemyType;
}
Enemy * EnemyType::BlueEnemy(SDL_Point pos)
{
	//Fast small blue enemy
	enemyType = new Enemy(pos, { pos.x, pos.y, 10, 10 }, { 0, 0, 255, 255 }, 150);
	return enemyType;
}
Enemy * EnemyType::RedEnemy(SDL_Point pos)
{
	//Slow big red enemy
	enemyType = new Enemy(pos, { pos.x, pos.y, 30, 30 }, { 255, 0, 0, 255 }, 50);
	return enemyType;
}
