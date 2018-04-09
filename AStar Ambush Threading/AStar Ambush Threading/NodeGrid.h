#pragma once

#include "stdafx.h"
#include "Node.h"
#include "Arc.h"
#include <vector>

class NodeGrid 
{
public:
	NodeGrid() {}
	//NodeGrid(std::vector<Vector> &nodeData);

	void addNode(SDL_Point pos, std::string id);
	std::vector<Node*> getNodes();

	void addArcs();

	void draw(SDL_Renderer* renderer);

	void setColumnSize(int col);
	int getNodesSize();


private:

	std::vector<Node*> m_nodes;
	int m_column;

};