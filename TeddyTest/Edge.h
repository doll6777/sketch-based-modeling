#pragma once
#include <vgl.h>
#include <vec.h>

class CEdge
{
public:
	int mVind[2];

	CEdge();
	CEdge(int s, int e);

	~CEdge();
};

