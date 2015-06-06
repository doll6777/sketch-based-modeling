#pragma once
#include <list>
#include <vgl.h>
#include <vec.h>
#include "Drawing.h"
#include "MeshCreation.h"

using namespace std;

class CSceneManager
{
public:
	~CSceneManager(void);

	CDrawing DrawTool;
	CMeshCreation MeshCreation;

	int screenWidth = 1280;
	int screenHeight = 680;

	void PushPointList(CVertex v)
	{
		pointList.push_back(v);
	}

	list<CVertex> GetPointList(void)
	{
		return pointList;
	}

	static CSceneManager& GetInstance(void);
	static CSceneManager* GetPointer(void);

private:
	CSceneManager(void);
	list<CVertex> pointList;
};

