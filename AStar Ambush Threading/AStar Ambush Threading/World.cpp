#include "World.h"

World::World(EventListener *listener)
{
	setupWorld();
	m_player = Player{ Vector{20, 20},  5, 5, SDL_Color{ 100, 100, 200, 255 }, listener};
}

void World::update(float deltaTime) {
	m_player.update(deltaTime);
}

void World::draw(SDL_Renderer *renderer) {
	for (int i = 0; i < m_tiles.size(); i++) 
	{
		m_tiles.at(i)->draw(renderer);
	}
	m_player.draw(renderer);
}

void World::setupWorld() {

	for (int i = 0; i < gWidth; i++) 
	{
		for (int j = 0; j < gHeigth; j++) 
		{
			if (i == 0) {
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else if (i == gWidth - 1) {
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else if (j == 0) {
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else if (j == gHeigth - 1) {
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else if (i > 0 && i <= 215 && j > 30 && j <= 35) 
			{
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else if (i > 40 && i <= 255 && j > 70 && j <= 75) 
			{
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else if (i > 0 && i <= 215 && j > 105 && j <= 110) 
			{
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 255, 255, 255, 255 }, "Wall"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Wall");
			}
			else {
				m_tiles.push_back(new Tile(Vector{ i * 5.0f, j * 5.0f }, 5, 5, SDL_Color{ 0, 0, 0, 255 }, "Floor"));
				m_layout.addNode(Vector{ i * 5.0f, j * 5.0f }, "Floor");
			}
		}
	}
}