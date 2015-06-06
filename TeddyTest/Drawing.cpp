#include "Drawing.h"


CDrawing::CDrawing()
{
}

CDrawing::~CDrawing()
{
}

 void CDrawing::DrawPolygon(list<CVertex> vertexList)
{
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);

	for (list<CVertex>::iterator it(vertexList.begin()); it != vertexList.end(); it++)
	{
		glVertex2f(it->mPos.x, it->mPos.y);
	}
	glEnd();
}
