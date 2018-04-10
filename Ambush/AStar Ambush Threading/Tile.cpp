#include "Tile.h"

Tile::Tile(SDL_Point pos, int width, int height, SDL_Color colour, std::string id) {
	m_pos = pos;

	m_rect.x = pos.x;
	m_rect.y = pos.y;
	m_rect.w = width;
	m_rect.h = height;

	m_colour = colour;
	m_id = id;
}

std::string Tile::getID() {
	return m_id;
}