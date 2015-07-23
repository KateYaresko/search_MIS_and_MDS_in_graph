#pragma once
#include <vector>
#include <fstream>
#include "Vertex.h"

class Graph
{
public:
	Graph(void);
	~Graph(void);
	std::vector<Vertex> vertex;
	void initFromFile(std::ifstream &in);
	void addVertex(std::vector<int> newNeighbours);
	void deleteVertex(int vert);
	void addEdge(int vert1, int vert2);
	void deleteEdge(int vert1, int vert2);
	bool isAllAdjacent(std::vector<int> candidates, std::vector<int> not);
};

