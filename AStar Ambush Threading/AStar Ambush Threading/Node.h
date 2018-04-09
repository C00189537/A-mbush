#pragma once

#include "stdafx.h"
#include "Arc.h"

#include <list>

class Node {
public:
	Node() {}
	//Node(Vector pos, int id);
	Node(SDL_Point pos, std::string id);

	void addArc(Node *n);
	float calculateArcWeight(SDL_Point otherNodePos);

	SDL_Point getPos();

	//int getID();
	std::string getID();

	bool getMarked();
	void setMarked(bool marked);

	Node* getPrevious();
	void setPrevious(Node *previous);

	float getHeuristic();
	void setHeuristic(float heuristic);

	float getCost();
	void setCost(float cost);

	std::list<Arc>& getArcs();

	void draw(SDL_Renderer* renderer);

private:
	//int m_id;
	std::string m_id;

	SDL_Point m_pos;

	bool m_marked; // if the node has been visited

	Node *m_previous; // pointer to previous node

	float m_cost;
	float m_heuristic;
	
	std::list<Arc> m_arcs; // list containing arcs to other nodes
};

