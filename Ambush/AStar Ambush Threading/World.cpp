#include "World.h"

int distance(SDL_Point p1, SDL_Point p2);

World::World()
{

}
void World::create(Keys *k)
{
	m_wallsize = { (m_screenWidth / m_gWidth), (m_screenHeight / m_gHeigth) };
	enemyPool = new	EnemyType();
	aWholeNewWorld();
	m_nodes.setColumnSize(30);
	m_nodes.addArcs();
	
	m_playerSpawn = { (m_screenWidth / 100) * 20, (m_screenHeight / 100) * 10, (m_screenWidth / 100) * 20, (m_screenHeight / 100) * 30};
	m_enemySpawn = { (m_screenWidth / 100) * 15, (m_screenHeight / 100) * 60, (m_screenWidth / 100) * 30, (m_screenHeight / 100) * 30 };

	//Spawn enemies and player in their zones
	spawnPoints();
	createPlayer(k);
	createEnemies();

	m_astar = new AStar(m_nodes);
	
}
void World::update(float deltaTime) 
{
	m_player.update(deltaTime);
}
void World::draw(SDL_Renderer *r) 
{
	for (int i = 0; i < m_walls.size(); i++) 
	{
		m_walls.at(i)->draw(r);
	}

	SDL_SetRenderDrawColor(r, 255, 255, 255, 100);
	SDL_RenderFillRect(r, &m_playerSpawn);
	SDL_RenderFillRect(r, &m_enemySpawn);

	SDL_SetRenderDrawColor(r, 255, 0, 255, 255);
	/*for (int i = 0; i < nodePos.size(); i++)
	{	
		SDL_RenderDrawPoints(renderer, &nodePos.at(i), 1);
	}*/
	m_nodes.draw(r);
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies.at(i)->draw(r);
	}
	m_player.draw(r);
}

void World::aWholeNewWorld() {

	for (int i = 0; i < m_gWidth; i++) 
	{
		for (int j = 0; j < m_gHeigth; j++) 
		{
			if (i == 0) 
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else if (j == 0)
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else if (i == m_gWidth - 1)
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else if (j == m_gHeigth - 1) 
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else if (i > 0 && i <= (m_gWidth / 5) * 4 && j == m_gHeigth / 2)
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 255, 0, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else if (i > (m_gWidth / 8) && i <= (m_gWidth / 4) * 3 &&  j == (m_gHeigth / 4) * 3)
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 0, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else if (i > (m_gWidth / 3) && i <= (m_gWidth / 6) * 5 && j == m_gHeigth / 4)
			{
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 255, 255, 0, 255 }, "Wall"));
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Wall");
			}
			else 
			{
				//Floor
				m_walls.push_back(new Tile({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) }, m_wallsize.x, m_wallsize.y, SDL_Color{ 0, 0, 0, 255 }, "Floor"));
				m_floors.push_back({ i * (m_screenWidth / m_gWidth), j * (m_screenHeight / m_gHeigth) });
				nodePos.push_back({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) });
				m_nodes.addNode({ i * (m_screenWidth / m_gWidth) + (m_wallsize.x / 2), j * (m_screenHeight / m_gHeigth) + (m_wallsize.y / 2) }, "Floor");
			}
		}
	}
}

void World::checkCollision(int i)
{
	SDL_Rect result = {0, 0};

	if (m_walls.at(i)->getID() == "Wall")
	{
		if (SDL_IntersectRect(&m_player.getRect(), &m_walls.at(i)->getRect(), &result))
		{
			if (result.w > result.h)
			{
				if (m_player.getPos().y > m_walls.at(i)->getPos().y)
				{
					//set the player position back to the temp rect plus the x position stays the same
					m_player.setPos({ m_player.getPos().x, m_player.getRect().y + result.h });
				}
				else
				{
					m_player.setPos({ m_player.getPos().x, m_player.getRect().y - result.h });
				}
				m_player.setVelocity({ m_player.getVelocity().x, 0 });
			}
			else
			{
				if (m_player.getPos().x > m_walls.at(i)->getPos().x)
				{
					m_player.setPos({ m_player.getRect().x + result.w, m_player.getPos().y });
				}
				else
				{
					m_player.setPos({ m_player.getRect().x - result.w, m_player.getPos().y });
				}
				m_player.setVelocity({ 0, m_player.getVelocity().y });
			}
		}
	}
}

int World::tileSize()
{
	return m_walls.size();
}
int World::enemySize()
{
	return m_enemies.size();
}

void World::createEnemies()
{
	srand(SDL_GetTicks());
	

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		SDL_Point pos = { m_enemySpawnPoints.at(rand() % m_enemySpawnPoints.size()).x,  m_enemySpawnPoints.at(rand() % m_enemySpawnPoints.size()).y };

		switch ((rand() % 3) + 1)
		{
		case 1:
			m_enemies.push_back(enemyPool->BlueEnemy({ pos.x, pos.y }));
			break;
		case 2:
			m_enemies.push_back(enemyPool->GreenEnemy({ pos.x, pos.y }));
			break;
		case 3:
			m_enemies.push_back(enemyPool->RedEnemy({ pos.x, pos.y }));
			break;
		}
	}
}

void World::spawnPoints()
{

	for (int i = 0; i < m_floors.size(); i++)
	{
		if (m_floors.at(i).x >= (m_screenWidth / 100) * 20 
			&& m_floors.at(i).x <= (m_screenWidth / 100) * 20 + (m_screenWidth / 100) * 20
			&& m_floors.at(i).y >= (m_screenHeight / 100) * 10
			&& m_floors.at(i).y <= (m_screenHeight / 100) * 10 + (m_screenHeight / 100) * 30)
		{
			m_playerSpawnPoints.push_back(m_floors.at(i));
		}

		if (m_floors.at(i).x >= (m_screenWidth / 100) * 15
			&& m_floors.at(i).x <= (m_screenWidth / 100) * 15 + (m_screenWidth / 100) * 29
			&& m_floors.at(i).y >= (m_screenHeight / 100) * 60
			&& m_floors.at(i).y <= (m_screenHeight / 100) * 60 + (m_screenHeight / 100) * 29)
		{
			m_enemySpawnPoints.push_back(m_floors.at(i));
		}
	}

}

void World::createPlayer(Keys* k)
{
	srand(SDL_GetTicks());
	SDL_Point pos = { m_playerSpawnPoints.at(rand() % m_playerSpawnPoints.size()).x,  m_playerSpawnPoints.at(rand() % m_playerSpawnPoints.size()).y };
	m_player = Player{ { pos.x, pos.y },{ pos.x, pos.y, 20, 20 }, SDL_Color{ 255, 165, 0, 255 }, k };
	

}
int World::proximityNode(SDL_Point p)
{
	SDL_Point result = {0, 0};
	float smallest = 100000;
	int tempInt = 0;

	
	for (int i = 0; i < m_nodes.getNodesSize(); i++)
	{
		if (m_nodes.getNodes().at(i)->getID() == "Floor")
		{	
			float temp = distance(m_player.getPos(), m_nodes.getNodes().at(i)->getPos());
			if (temp < smallest)
			{
				smallest = temp;
				tempInt = i;
			}
		}
	}
	return tempInt;
}
void World::enemyPath(int i)
{
	m_astar->calculatePath(m_nodes.getNodes().at(proximityNode(m_enemies.at(i)->getPos())), m_nodes.getNodes().at(proximityNode(m_player.getPos())), m_enemies.at(i)->nodePath);
	//std::cout << "Path made" << std::endl;
}
int distance(SDL_Point p1, SDL_Point p2)
{
	return sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}