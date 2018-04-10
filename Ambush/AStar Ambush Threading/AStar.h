#pragma once

#include "NodeGrid.h"
#include "NodeCostComparer.h"
#include <queue>

class AStar 
{
public:
	
	AStar(NodeGrid &nodes);
	void calculatePath(Node* pStart, Node* pDest, std::vector<Node*>& path);

private:

	NodeGrid & m_NodeGrid;
	void ucs(Node* pStart, Node* pDest, std::vector<Node*>& path);
};