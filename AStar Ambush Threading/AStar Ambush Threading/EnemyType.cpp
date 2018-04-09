#include "EnemyType.h"

Enemy * EnemyType::GreenEnemy(Vector pos)
{
	//Average green enemy
	enemyType = new Enemy(pos, 20, 20, { 0, 255, 255 }, 100);
	return enemyType;
}
Enemy * EnemyType::BlueEnemy(Vector pos)
{
	//Fast small blue enemy
	enemyType = new Enemy(pos, 10, 10, { 0, 0, 255, 255 }, 150);
	return enemyType;
}
Enemy * EnemyType::RedEnemy(Vector pos)
{
	//Slow big red enemy
	enemyType = new Enemy(pos, 30, 30, { 255, 0, 0, 255 }, 50);
	return enemyType;
}
