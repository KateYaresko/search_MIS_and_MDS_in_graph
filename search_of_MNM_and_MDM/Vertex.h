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

	std::vector<int> adjacent; // ������� ���������
	std::vector<int> inversion; // �������� ������� ���������
	std::vector<int> inversionT; // ����������������� �������� ������� ���������
	std::vector<int> notAdjacent; // ������� �����������
	std::vector<Dot> coord; // ������� ���������
};

