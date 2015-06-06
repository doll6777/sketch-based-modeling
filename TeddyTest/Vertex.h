#pragma once
#include <vgl.h>
#include <vec.h>

class CVertex
{
public:
	vec3 mPos;
	CVertex();
	CVertex(vec3 v)
	{
		mPos = v;
	}
	~CVertex();
};

