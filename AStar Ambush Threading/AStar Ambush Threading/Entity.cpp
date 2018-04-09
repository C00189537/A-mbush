#include "Entity.h"

Entity::Entity(SDL_Point pos, SDL_Rect r, SDL_Color colour) {
	m_pos = pos;

	m_rect = r;

	m_colour = colour;
}

void Entity::draw(SDL_Renderer *renderer) 
{
	SDL_SetRenderDrawColor(renderer, m_colour.r, m_colour.g, m_colour.b, m_colour.a);
	SDL_RenderFillRect(renderer, &m_rect);
}

void Entity::setPos(int x, int y) {
	m_pos.x = x;
	m_pos.y = y;
}

void Entity::setPos(SDL_Point pos) 
{
	m_pos = pos;
}

SDL_Point Entity::getPos() 
{
	return m_pos;
}
SDL_Rect Entity::getRect()
{
	return m_rect;
}
void Entity::setRect(SDL_Rect r)
{
	m_rect = r;
	m_pos.x = m_rect.x;
	m_pos.y = m_rect.y;
}