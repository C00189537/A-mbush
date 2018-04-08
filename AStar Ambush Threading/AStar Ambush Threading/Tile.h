#pragma once

#include "Entity.h"
#include "Node.h"

class Tile : public Entity {
public:
	Tile() {}
	Tile(Vector pos, int width, int height, SDL_Color colour, std::string id);

	std::string getID();

private:
	std::string m_id;
};