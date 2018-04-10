#pragma once

#include "Tile.h"
#include "Player.h"
#include "Keys.h"
#include "NodeGrid.h"
#include "AStar.h"
#include "InputHandler.h"
#include "EnemyType.h"

class World {
public:
	World();

	void create(Keys *k);
	void update(float deltaTime);
	void draw(SDL_Renderer *r);
	void checkCollision(int i);
	int tileSize();

	std::vector<Enemy*> enemies;
	Spawner* enemyPool;
	void createEnemies();
	bool generateEnemiesPath = true;
	const int MAX_ENEMIES = 500;
private:

	Player m_player;

	//Nodes for A*
	NodeGrid m_nodes;
	std::vector<Tile*> m_walls;
	std::vector<Tile*> m_floors;


	void aWholeNewWorld();

	int m_gWidth = 100, m_gHeigth = 100;
	int m_screenWidth = 1280,m_screenHeight = 720;
	SDL_Point m_wallsize;

	std::vector<SDL_Point> nodePos;

	SDL_Rect m_playerSpawn, m_enemySpawn;
};