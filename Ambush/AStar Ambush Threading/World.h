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

	int m_gWidth = 100, m_gHeigth = 100;
	int m_screenWidth = 1920,m_screenHeight = 1080;
	SDL_Point m_wallsize;

	std::vector<SDL_Point> nodePos;
};