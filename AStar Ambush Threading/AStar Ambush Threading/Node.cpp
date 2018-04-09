#include "Node.h"

//Node::Node(Vector pos, int id) {
//	m_pos = pos;
//	m_id = id;
//}

Node::Node(SDL_Point pos, std::string id) 
{
	m_pos = pos;
	m_id = id;
}

void Node::addArc(Node *n) {
	Arc arc;

	arc.setNode(n);
	if (n->getID() == "Floor")
	{
		arc.setWeight(1);
	}
	else if (n->getID() == "Wall")
	{
		arc.setWeight(500000);
	}

	m_arcs.push_back(arc);
}

float Node::calculateArcWeight(SDL_Point otherNodePos) {
	return sqrt(((otherNodePos.x - m_pos.x) * (otherNodePos.x - m_pos.x)) + ((otherNodePos.y - m_pos.y) * (otherNodePos.y - m_pos.y)));
}

SDL_Point Node::getPos() {
	return m_pos;
}

//int Node::getID() {
//	return m_id;
//}

std::string Node::getID() {
	return m_id;
}

bool Node::getMarked() {
	return m_marked;
}

void Node::setMarked(bool marked) {
	m_marked = marked;
}

Node* Node::getPrevious() {
	return m_previous;
}

void Node::setPrevious(Node* previous) {
	m_previous = previous;
}

float Node::getHeuristic() {
	return m_heuristic;
}

void Node::setHeuristic(float heuristic) {
	m_heuristic = heuristic;
}

float Node::getCost() {
	return m_cost;
}

void Node::setCost(float cost) {
	m_cost = cost;
}

std::list<Arc>& Node::getArcs() {
	return m_arcs;
}

void Node::draw(SDL_Renderer *renderer)
{
	for (std::list<Arc>::iterator i = m_arcs.begin(); i != m_arcs.end(); i++)
	{
		SDL_RenderDrawLine(renderer, m_pos.x, m_pos.y, (*i).getNode()->getPos().x, (*i).getNode()->getPos().y);
	}
}