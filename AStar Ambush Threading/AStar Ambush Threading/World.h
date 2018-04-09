#pragma once

#include "Tile.h"
#include "Player.h"
#include "Keys.h"
#include "NodeGrid.h"
#include "AStar.h"
#include "InputHandler.h"

class World {
public:
	World();

	void create(Keys *k);
	void update(float deltaTime);
	void draw(SDL_Renderer *renderer);
	void checkCollision(int i);
	int tileSize();

private:

	Player m_player;

	//Nodes for A*
	NodeGrid m_nodes;
	std::vector<Tile*> m_walls;

	void aWholeNewWorld();

	int m_gWidth = 64, m_gHeigth = 36;
	int m_screenWidth = 1280,m_screenHeight = 720;
	int m_tileX = 20, m_tileY = 20, m_wallsize = 20;

	std::vector<SDL_Point> nodePos;
};