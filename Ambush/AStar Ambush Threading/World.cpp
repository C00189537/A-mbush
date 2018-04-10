#include "World.h"

World::World()
{

}
void World::create(Keys *k)
{
	m_wallsize = { (m_screenWidth / m_gWidth), (m_screenHeight / m_gHeigth) };
	enemyPool = new	EnemyType();
	aWholeNewWorld();
	m_nodes.setColumnSize(100);
	m_nodes.addArcs();
	m_player = Player{ {100, 50}, {100, 50, 20, 20}, SDL_Color{ 255, 165, 0, 255 }, k };
	m_playerSpawn = { (m_screenWidth / 100) * 40, (m_screenHeight / 100) * 10, (m_screenWidth / 100) * 20, (m_screenHeight / 100) * 30};
	m_enemySpawn = { (m_screenWidth / 100) * 25, (m_screenHeight / 100) * 60, (m_screenWidth / 100) * 40, (m_screenHeight / 100) * 30 };
	createEnemies();
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
	//m_nodes.draw(renderer);
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i)->draw(r);
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
				if (m_player.getRect().y > m_walls.at(i)->getRect().y)
				{
					m_player.setPos(m_player.getPos().x, m_player.getPos().y + result.h);
					m_player.setVelocity({ m_player.getVelocity().x, 0 });
				}
				else
				{
					m_player.setPos(m_player.getPos().x, m_player.getPos().y - result.h);
					m_player.setVelocity({ m_player.getVelocity().x, 0 });
				}
			}
			else
			{
				if (m_player.getRect().x > m_walls.at(i)->getRect().x)
				{
					m_player.setPos(m_player.getPos().x + result.w, m_player.getPos().y);
					m_player.setVelocity({ 0, m_player.getVelocity().y });
				}
				else
				{
					m_player.setPos(m_player.getPos().x - result.w, m_player.getPos().y);
					m_player.setVelocity({ 0, m_player.getVelocity().y });
				}
			}
		}
	}

}

int World::tileSize()
{
	return m_walls.size();
}

void World::createEnemies()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		switch ((rand() % 3) + 1)
		{
		case 1:
			enemies.push_back(enemyPool->BlueEnemy({ 100, 50 }));
			break;
		case 2:
			enemies.push_back(enemyPool->GreenEnemy({ 200, 50 }));
			break;
		case 3:
			enemies.push_back(enemyPool->RedEnemy({ 300, 50 }));
			break;
		}
	}
}