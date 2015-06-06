#pragma once
#include <vgl.h>
#include <list>
#include <vec.h>
#include "Mesh.h"

using namespace std;

class CDrawing
{
public:
	void DrawPolygon(list<CVertex> vertexList);
	void DrawMesh();
	void DrawUI();

	CDrawing();
	~CDrawing();
};

