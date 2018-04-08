#include "World.h"

World::World()
{
	
}
void World::create(EventListener *listener)
{
	setupWorld();
	m_layout.setNodesPerLine(36);
	m_layout.addArcs();
	m_player = Player{ Vector{ 20, 20 },  20, 20, SDL_Color{ 0, 255, 255, 255 }, listener };
}
void World::update(float deltaTime) 
{
	m_player.update(deltaTime);
}

void World::draw(SDL_Renderer *renderer) {
	for (int i = 0; i < m_tiles.size(); i++) 
	{
		m_tiles.at(i)->draw(renderer);
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	for (int i = 0; i < nodePos.size(); i++)
	{	
		SDL_RenderDrawPoints(renderer, &nodePos.at(i), 1);
	}
	m_layout.draw(renderer);

	m_player.draw(renderer);
}

void World::setupWorld() {

	for (int i = 0; i < gWidth; i++) 
	{
		for (int j = 0; j < gHeigth; j++) 
		{
			if (i == 0) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else if (i == gWidth - 1) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else if (j == 0) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else if (j == gHeigth - 1) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else if (i > 0 && i <= 55 && j == 8) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else if (i > 10 && i <= 100 && j == 18) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else if (i > 0 && i <= 55 && j == 26) 
			{
				m_tiles.push_back(new Tile(Vector{ i * m_tileX, j * m_tileY }, m_tileSize, m_tileSize, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Wall");
			}
			else 
			{
				nodePos.push_back({ (i * (int)m_tileX) + 10, (j * (int)m_tileY) + 10 });
				//Node creation
				m_layout.addNode({ (i * m_tileX) + 10, (j * m_tileY) + 10 }, "Floor");
			}
		}
	}
}

void World::checkCollision(int i)
{
	SDL_Rect result = {0, 0};
	if (SDL_IntersectRect(&m_player.getRect(), &m_tiles.at(i)->getRect(), &result))
	{
		if (result.w > result.h)
		{
			if (m_player.getRect().y > m_tiles.at(i)->getRect().y)
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
			if (m_player.getRect().x > m_tiles.at(i)->getRect().x)
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
	return m_tiles.size();
}
