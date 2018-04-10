#include "World.h"

World::World()
{
	
}
void World::create(Keys *k)
{
	m_wallsize = { (m_screenWidth / m_gWidth), (m_screenHeight / m_gHeigth) };
	aWholeNewWorld();
	m_nodes.setColumnSize(100);
	m_nodes.addArcs();
	m_player = Player{ {100, 50}, {100, 50, 20, 20}, SDL_Color{ 255, 165, 0, 255 }, k };
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
	/*for (int i = 0; i < nodePos.size(); i++)
	{	
		SDL_RenderDrawPoints(renderer, &nodePos.at(i), 1);
	}*/
	//m_nodes.draw(renderer);

	m_player.draw(renderer);
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
			else if (i > 5 && i <= 70 && j == (m_gHeigth / 4) * 3)
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
	}
	//std::cout << m_player.getRect().x << ", " << m_player.getRect().y << std::endl;
}
int World::tileSize()
{
	return m_walls.size();
}
