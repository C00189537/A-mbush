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
	std::vector<Tile*> m_walls;

	Player m_player;

	NodeLayout m_layout;

	void setupWorld();

	float gWidth = 64, gHeigth = 36;
	float screenWidth = 1280, screenHeight = 720;
	float m_tileX = 20, m_tileY = 20, m_wallsize = 20;

	std::vector<SDL_Point> nodePos;
};