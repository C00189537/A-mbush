#include "EnemyType.h"

Enemy * EnemyType::GreenEnemy(SDL_Point pos)
{
	//Average green enemy
	enemyType = new Enemy(pos, {pos.x, pos.y, 20, 20 }, { 0, 255, 0 , 255}, 100);
	enemyType->setID("Green");
	return enemyType;
}
Enemy * EnemyType::BlueEnemy(SDL_Point pos)
{
	//Fast small blue enemy
	enemyType = new Enemy(pos, { pos.x, pos.y, 10, 10 }, { 0, 0, 255, 255 }, 150);
	enemyType->setID("Blue");
	return enemyType;
}
Enemy * EnemyType::RedEnemy(SDL_Point pos)
{
	//Slow big red enemy
	enemyType = new Enemy(pos, { pos.x, pos.y, 30, 30 }, { 255, 0, 0, 255 }, 50);
	enemyType->setID("Red");
	return enemyType;
}
