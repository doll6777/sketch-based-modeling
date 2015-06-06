#pragma once
#include "Mesh.h"


class CMeshDeformation
{
public:
	void DoPull(CMesh* mesh);
	void DoPush(CMesh* mesh);
	void DoPaint(CMesh* mesh);
	void MeshUpdate(CMesh* mesh);
	void DoSubdivision(CMesh* mesh);

	CMeshDeformation();
	~CMeshDeformation();
};

