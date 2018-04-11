#include "AStar.h"

AStar::AStar(NodeGrid &nodes) : m_NodeGrid(nodes)
{

}

void AStar::calculatePath(Node* start, Node* dest, std::vector<Node*>& path) 
{
	if (start != NULL) {
		// actual cost
		ucs(dest, start, path);

		for (int i = 0; i < m_NodeGrid.getNodesSize() - 1; i++) 
		{
			// heuristic
			m_NodeGrid.getNodes()[i]->setHeuristic(m_NodeGrid.getNodes()[i]->getCost() * 0.9);
			m_NodeGrid.getNodes()[i]->setCost(99999);
		}

		// sets up priority queue that compares the total cost and heuristic cost
		std::priority_queue<Node*, std::vector<Node*>, NodeSearchCostComparerAStar> priorityQueue;

		// set the cost to reach the start to be 0
		start->setCost(0);

		priorityQueue.push(start);
		start->setMarked(true);

		//run until dest is reached
		while (priorityQueue.size() != 0 && priorityQueue.top() != dest)
		{
			auto iter = priorityQueue.top()->getArcs().begin();
			auto endIter = priorityQueue.top()->getArcs().end();

			for (; iter != endIter; iter++) 
			{
				// increases the running weight total
				float distC = priorityQueue.top()->getCost() + (*iter).getWeight();

				// compares node weights
				if (distC < (*iter).getNode()->getCost()) 
				{
					(*iter).getNode()->setCost(distC);
					// sets previous node
					(*iter).getNode()->setPrevious(priorityQueue.top());
				}
				// marks node as visited
				if ((*iter).getNode()->getMarked() == false)
				{
					priorityQueue.push((*iter).getNode());
					(*iter).getNode()->setMarked(true);
				}

				if ((*iter).getNode() == dest) 
				{
					Node* temp = dest;

					if (distC <= (*iter).getNode()->getCost()) 
					{
						if (path.empty() != true) {
							path.clear();
						}

						while (temp != start) 
						{
							// backtrack
							path.push_back(temp);
							temp = temp->getPrevious(); 
						}
						path.push_back(start);
					}
				}
			}

			priorityQueue.pop();
		}
	}

	// resets nodes
	for (int i = 0; i < m_NodeGrid.getNodesSize() - 1; i++) 
	{
		m_NodeGrid.getNodes()[i]->setMarked(false);
	}
}

void AStar::ucs(Node* start, Node* dest, std::vector<Node*>& path) 
{
	if (start != NULL) {
		for (int i = 0; i < m_NodeGrid.getNodesSize() - 1; i++) 
		{
			m_NodeGrid.getNodes()[i]->setCost(99999);
		}

		std::priority_queue<Node*, std::vector<Node*>, NodeSearchCostComparerUCS> priorityQueue;
		start->setCost(0);

		//sets starting node
		priorityQueue.push(start);
		start->setMarked(true);
		//Run until dest is reached
		while (priorityQueue.size() != 0 && priorityQueue.top() != dest) 
		{
			auto iter = priorityQueue.top()->getArcs().begin();
			auto endIter = priorityQueue.top()->getArcs().end();

			//Adds acr weight
			for (; iter != endIter; iter++) 
			{
				float distC = priorityQueue.top()->getCost() + (*iter).getWeight();

				// compares weights of nodes to see if its less
				if (distC < (*iter).getNode()->getCost()) 
				{
					(*iter).getNode()->setCost(distC);

					// sets previous node
					(*iter).getNode()->setPrevious(priorityQueue.top());
				}
				//Mark the node as visited
				if ((*iter).getNode()->getMarked() == false) 
				{
					priorityQueue.push((*iter).getNode());
					(*iter).getNode()->setMarked(true);
				}

				if ((*iter).getNode() == dest) 
				{
					Node* temp = dest;
				
					if (distC <= (*iter).getNode()->getCost()) 
					{
						if (path.empty() != true) {

							path.clear();
						}
						//backtrack until you reach the start
						while (temp != start)
						{
							path.push_back(temp);
							temp = temp->getPrevious(); 
						}
						path.push_back(start);
					}
				}
			}
			priorityQueue.pop();
		}
	}

	// resets nodes
	for (int i = 0; i < m_NodeGrid.getNodesSize() - 1; i++) 
	{
		m_NodeGrid.getNodes()[i]->setMarked(false);
	}
}

