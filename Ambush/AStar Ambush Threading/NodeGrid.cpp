#include "NodeGrid.h"

void NodeGrid::addNode(SDL_Point pos, std::string id) 
{
	m_nodes.push_back(new Node(pos, id));
}

void NodeGrid::addArcs()
{
	int columnIndex = 1;
	for (int i = 0; i < m_nodes.size(); i++)
	{
		if (i == (m_column * columnIndex))
		{
			columnIndex++;
		}
		if ((i + m_column) < m_nodes.size())
		{
			m_nodes.at(i)->addArc(m_nodes.at(i + m_column));
			m_nodes.at(i + m_column)->addArc(m_nodes.at(i));
		}
		if ((i + 1) < m_nodes.size())
		{
			if (i < (m_column * columnIndex) - 1)
			{
				m_nodes.at(i)->addArc(m_nodes.at(i + 1));
				m_nodes.at(i + 1)->addArc(m_nodes.at(i));
			}
		}
	}
}
void NodeGrid::draw(SDL_Renderer* renderer)
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		m_nodes.at(i)->draw(renderer);
	}
}
std::vector<Node*> NodeGrid::getNodes()
{
	return m_nodes;
}
void NodeGrid::setColumnSize(int col)
{
	m_column = col;
}
int NodeGrid::getNodesSize() 
{
	return m_nodes.size();
}