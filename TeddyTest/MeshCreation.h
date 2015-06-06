#pragma once
#include <list>
#include <vgl.h>
#include <vec.h>
#include "Mesh.h"
#include <Fade_2D.h>

using namespace std;

#pragma comment(lib, "fade2D_vc12_Debug")

using namespace GEOM_FADE2D;

class CMeshCreation
{
public:
	float mEdgeLength;
	CMesh m3DMesh;
	CMesh m2DMesh;
	Fade_2D dt;
	std::vector<Segment2> vSegments;

    list<CVertex> InitPolygon(list<CVertex> pList);
	void FindSpine();
	void DoCDT();
	void FindChordalAxis();
	void DoPrunning();
	void DoSubdivision();
	void DoMeshConstruction();
	CMesh GetMesh();

	CMeshCreation();
	~CMeshCreation();
};

