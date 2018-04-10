#include "Player.h"

#include <iostream>

Player::Player(SDL_Point pos, SDL_Rect r, SDL_Color colour, Keys *k) 
{
	m_pos = pos;
	m_rect = r;

	m_colour = colour;
	m_speed = 100;

	m_velocity = { 0, 0 };
	m_keys = k;
}

void Player::update(float deltaTime) {
	
	inputHandle(deltaTime);
	
	m_pos.x += m_velocity.x;
	m_pos.y += m_velocity.y;

	friction();
	m_rect.x = m_pos.x;
	m_rect.y = m_pos.y;
}

void Player::inputHandle(float deltaTime)
{
	if (m_keys->A) 
	{
		m_velocity.x -= m_speed * deltaTime;
	}
	if (m_keys->D) 
	{
		m_velocity.x += m_speed * deltaTime;
	}
	if (m_keys->W) 
	{
		m_velocity.y -= m_speed * deltaTime;
	}
	if (m_keys->S) 
	{
		m_velocity.y += m_speed * deltaTime;
	}

}
void Player::setVelocity(SDL_Point v)
{
	m_velocity = v;
}
SDL_Point Player::getVelocity()
{
	return m_velocity;
}
void Player::friction()
{
	//Deal with max speed
	if (m_velocity.x >= MAX_XVEL)
	{
		m_velocity.x = MAX_XVEL;
	}
	if (m_velocity.x <= -MAX_XVEL)
	{
		m_velocity.x = -MAX_XVEL;
	}
	if (m_velocity.y >= MAX_XVEL)
	{
		m_velocity.y = MAX_YVEL;
	}
	if (m_velocity.y <= -MAX_XVEL)
	{
		m_velocity.y = -MAX_YVEL;
	}

	//Slow player
	if (m_velocity.x > 0)
	{
		m_velocity.x--;
	}
	else if (m_velocity.x < 0)
	{
		m_velocity.x++;
	}
	if (m_velocity.y > 0)
	{
		m_velocity.y--;
	}
	else if (m_velocity.y < 0)
	{
		m_velocity.y++;
	}

}