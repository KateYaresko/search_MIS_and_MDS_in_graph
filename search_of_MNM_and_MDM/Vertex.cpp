#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex(void)
{
}

Vertex::Vertex(int vert)
{
	adjacent.push_back(vert);
}

Vertex::~Vertex(void)
{
}

