#pragma once

#include "InputHandler.h"
#include "NodeLayout.h"
#include "Tile.h"
#include "Player.h"
#include "AStar.h"

class World {
public:
	World();

	void create(EventListener *listener);
	void update(float deltaTime);
	void draw(SDL_Renderer *renderer);
	void checkCollision(int i);
	int tileSize();

private:
	std::vector<Tile*> m_tiles;

	Player m_player;

	NodeLayout m_layout;

	void setupWorld();

	int gWidth = 64, gHeigth = 36;
	float m_tileX = 20, m_tileY = 20, m_tileSize = 20;

	std::vector<SDL_Point> nodePos;
};