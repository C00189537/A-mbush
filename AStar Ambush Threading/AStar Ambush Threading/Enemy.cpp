#include "Enemy.h"



Enemy::Enemy(Vector pos, int width, int height, SDL_Color colour, int speed) {
m_pos = pos;

m_rect.x = (int)pos.x;
m_rect.y = (int)pos.y;
m_rect.w = width;
m_rect.h = height;

m_colour = colour;
m_speed = 100;

}

