#pragma once
#include <vector>

struct Dot
{
	int x;
	int y;
};

class Vertex
{
public:
	Vertex(void);
	Vertex(int vert);

	~Vertex(void);

	std::vector<int> adjacent; // матрица смежности
	std::vector<int> inversion; // инверсия матрицы смежности
	std::vector<int> inversionT; // транспонированная инверсия матрицы смежности
	std::vector<int> notAdjacent; // матрица несмежности
	std::vector<Dot> coord; // матрица координат
};

