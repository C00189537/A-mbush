#include "World.h"

World::World()
{
	
}
void World::create(EventListener *listener)
{
	setupWorld();
	m_layout.setNodesPerLine(100);
	m_layout.addArcs();
	m_player = Player{ Vector{ 20, 20 },  20, 20, SDL_Color{ 0, 255, 255, 255 }, listener };
}
void World::update(float deltaTime) 
{
	m_player.update(deltaTime);
}

void World::draw(SDL_Renderer *renderer) 
{
	for (int i = 0; i < m_walls.size(); i++) 
	{
		m_walls.at(i)->draw(renderer);
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	for (int i = 0; i < nodePos.size(); i++)
	{	
		SDL_RenderDrawPoints(renderer, &nodePos.at(i), 1);
	}
	//m_layout.draw(renderer);

	m_player.draw(renderer);
}

void World::setupWorld() {

	for (int i = 0; i < gWidth; i++) 
	{
		for (int j = 0; j < gHeigth; j++) 
		{
			if (i == 0) 
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else if (i == gWidth - 1) 
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else if (j == 0) 
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else if (j == gHeigth - 1) 
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else if (i > 10 && i <= 55 && j == 8) 
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else if (i > (screenWidth / 100) && i <= ((screenWidth / 100) * 8) && j == ((screenHeight / 100) * 5))
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else if (i > 5 && i <= 50 && j == 26) 
			{
				m_walls.push_back(new Tile(Vector{ i * (screenWidth / gWidth), j * (screenHeight / gHeigth) }, m_wallsize, m_wallsize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Wall");
			}
			else 
			{
				nodePos.push_back({ i * (int)(screenWidth / gWidth) + 10, j * (int)(screenHeight / gHeigth) + 10 });
				//Node creation
				m_layout.addNode({ i * (screenWidth / gWidth) + 10, j * (screenHeight / gHeigth) + 10 }, "Floor");
			}
		}
	}
}

void World::checkCollision(int i)
{
	SDL_Rect result = {0, 0};
	if (SDL_IntersectRect(&m_player.getRect(), &m_walls.at(i)->getRect(), &result))
	{
		if (result.w > result.h)
		{
			if (m_player.getRect().y > m_walls.at(i)->getRect().y)
			{
				m_player.setPos(m_player.getPos().x, m_player.getPos().y + result.h);
			}
			else
			{
				m_player.setPos(m_player.getPos().x, m_player.getPos().y - result.h);
			}
		}
		else
		{
			if (m_player.getRect().x > m_walls.at(i)->getRect().x)
			{
				m_player.setPos(m_player.getPos().x + result.w, m_player.getPos().y);
			}
			else
			{
				m_player.setPos(m_player.getPos().x - result.w, m_player.getPos().y);
			}
		}
	}
	std::cout << m_player.getRect().x << ", " << m_player.getRect().y << std::endl;
}
int World::tileSize()
{
	return m_walls.size();
}
