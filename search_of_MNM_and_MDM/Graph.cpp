#include "stdafx.h"
#include "Graph.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

Graph::Graph(void){}
Graph::~Graph(void){}

void Graph::addVertex(std::vector<int> newNeighbours)
{
	Vertex tmpV;
	for(int i = 0; i < newNeighbours.size(); i++)
	{
		tmpV.adjacent.push_back(newNeighbours[i]);
		vertex[newNeighbours[i]].adjacent.push_back(vertex.size());
	}
	vertex.push_back(tmpV);	
}
void Graph::deleteVertex(int vert)
{
	for(int i = 0; i < vertex[vert].adjacent.size(); i++)
	{
		int k = vertex[vert].adjacent[i];
		for(int j = 0; j < vertex[k].adjacent.size(); j++)
			if(vertex[k].adjacent[j] == vert)
				vertex[k].adjacent.erase(vertex[k].adjacent.begin() + j);		
	}
	vertex.erase(vertex.begin() + vert);
	for(int i = 0; i < vertex.size(); i++)
		for(int j = 0; j < vertex[i].adjacent.size(); j++)
			if(vertex[i].adjacent[j] > vert) vertex[i].adjacent[j]--;
}
void Graph::addEdge(int vert1, int vert2)
{
	vertex[vert1].adjacent.push_back(vert2);
	vertex[vert2].adjacent.push_back(vert1);
}
void Graph::deleteEdge(int vert1, int vert2)
{
	std::vector<int>::iterator i = find(vertex[vert1].adjacent.begin(), vertex[vert1].adjacent.end(), vert2);
	vertex[vert1].adjacent.erase(i);
	i = find(vertex[vert2].adjacent.begin(), vertex[vert2].adjacent.end(), vert1);
	vertex[vert2].adjacent.erase(i);
}
void Graph::initFromFile(std::ifstream &in)
{
	std::string s;
	while (std::getline(in,s))
	{
		Vertex tmpV;
		std::istringstream iss (s, std::istringstream::in);
		int t;
		while (iss >> t)
			tmpV.adjacent.push_back(t);
		vertex.push_back(tmpV);
	}
}
bool Graph::isAllAdjacent(std::vector<int> candidates, std::vector<int> not)
{
	for(int i = 0; i < not.size(); i++)
	{
		int cnt = 0;
		for(int j = 0; j < vertex[not[i]].adjacent.size(); j++)
			for(int k = 0; k < candidates.size(); k++)		
				if(vertex[not[i]].adjacent[j] == candidates[k]) cnt++;
		if(cnt == 0) return false;
	}	
	return true;
}

