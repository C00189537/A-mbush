#include "Enemy.h"



Enemy::Enemy(SDL_Point pos, SDL_Rect r, SDL_Color colour, int speed) {
	m_pos = pos;

	m_rect = r;

	m_colour = colour;
	m_speed = 100;

}

void Enemy::update(float deltaTime)
{

}
