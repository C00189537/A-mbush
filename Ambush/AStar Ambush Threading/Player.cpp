#include "Player.h"

#include <iostream>

Player::Player(SDL_Point pos, SDL_Rect r, SDL_Color colour, Keys *k) 
{
	m_pos = pos;
	m_rect = r;

	m_colour = colour;
	m_speed = 100;

	m_keys = k;
}

void Player::update(float deltaTime) {
	
	inputHandle(deltaTime);
	m_rect.x = m_pos.x;
	m_rect.y = m_pos.y;
}

void Player::inputHandle(float deltaTime)
{
	if (m_keys->A) 
	{
		m_pos.x -= m_speed * deltaTime;
	}
	if (m_keys->D) 
	{
		m_pos.x += m_speed * deltaTime;
	}
	if (m_keys->W) 
	{
		m_pos.y -= m_speed * deltaTime;
	}
	if (m_keys->S) 
	{
		m_pos.y += m_speed * deltaTime;
	}
}
