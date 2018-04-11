#pragma once

#include "stdafx.h"


class Entity 
{
public:
	Entity() {}
	Entity(SDL_Point pos, SDL_Rect r, SDL_Color colour);

	void setPos(int x, int y);
	void setPos(SDL_Point pos);
	SDL_Point getPos();
	SDL_Rect getRect();
	void setRect(SDL_Rect r);

	void update(float deltaTime);
	void draw(SDL_Renderer *renderer);

	void setID(std::string id) { m_id = id; };
	std::string getID() { return m_id; };

protected:

	SDL_Point m_pos;
	SDL_Rect m_rect;
	SDL_Color m_colour;
	std::string m_id;
};