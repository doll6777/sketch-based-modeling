#pragma once

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include <list>

using namespace std;

class CMesh
{
public:
	
	list<CVertex> mVertexList;
	list<CEdge> mEdgeList;
	list<CFace> mFaceList;

	CMesh();
	~CMesh();
};

