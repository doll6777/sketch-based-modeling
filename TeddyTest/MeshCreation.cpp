#include "MeshCreation.h"




CMeshCreation::CMeshCreation()
{
}


CMeshCreation::~CMeshCreation()
{
}

// Find Coarse Edges
list<CVertex> CMeshCreation::InitPolygon(list<CVertex> pList)
{
	mEdgeLength = 0.05f;
	CVertex st = *pList.begin();
	dt.insert(Point2(st.mPos[0], st.mPos[1]));

	CVertex ed;

	m2DMesh.mVertexList.push_back(st);

	for (list<CVertex>::iterator it = pList.begin(); it != pList.end(); it++)
	{
		ed = *it;
		float len = (ed.mPos[0] - st.mPos[0])*(ed.mPos[0] - st.mPos[0]) + (ed.mPos[1] - st.mPos[1])*(ed.mPos[1] - st.mPos[1]);

		if (len > mEdgeLength*mEdgeLength)
		{
			m2DMesh.mVertexList.push_back(CVertex(ed));
			m2DMesh.mEdgeList.push_back(CEdge(m2DMesh.mVertexList.size() - 1, m2DMesh.mVertexList.size()));

			Point2 p0(st.mPos[0], st.mPos[1]);
			Point2 p1(ed.mPos[0], ed.mPos[1]);

			dt.insert(p1);
			vSegments.push_back(Segment2(p0, p1));

			st = ed;
		}
	}

	// st + ed
	st = *pList.begin();
	ed = m2DMesh.mVertexList.back();
	m2DMesh.mVertexList.push_back(st);
	
	Point2 p0(st.mPos[0], st.mPos[1]);
	Point2 p1(ed.mPos[0], ed.mPos[1]);
	//dt.insert(p0);
	vSegments.push_back(Segment2(p1, p0));

	return m2DMesh.mVertexList;
}

void customVisualization(Zone2* pZone, const std::string& name)
{
	// Create a Visualizer2 object with the output filename "example5.ps"
	Visualizer2 vis(name);
#if 1
	// Extract the triangles of the zone
	std::vector<Triangle2*> vTriangles;
	pZone->getTriangles(vTriangles);
	std::cout << "The zone consists of " << vTriangles.size() << " triangles" << std::endl;
	// Draw the zone triangles in red
	for (std::vector<Triangle2*>::iterator it(vTriangles.begin()); it != vTriangles.end(); ++it)
	{
		vis.addObject(**it, Color(1, 0, 0, 0.01, true)); // true means it is the fill color
	}
	// Draw the borders of the zone triangles
	for (std::vector<Triangle2*>::iterator it(vTriangles.begin()); it != vTriangles.end(); ++it)
	{
		vis.addObject(**it, Color(0, 0, 0, 0.01, false));
	}
#endif
#if 0
	// Retrieve the triangles of the triangulation. Draw them in black
	std::vector<Triangle2*> vAllDelaunayTriangles;
	dt.getTrianglePointers(vAllDelaunayTriangles);
	for (std::vector<Triangle2*>::iterator it = vAllDelaunayTriangles.begin(); it != vAllDelaunayTriangles.end();
		++it)
	{
		Triangle2* t(*it);
		Point2* p0 = t->getCorner(0);
		Point2* p1 = t->getCorner(1);
		Point2* p2 = t->getCorner(2);
		vis.addObject(Segment2(*p0, *p1), Color(1, 0, 0, 0.01));
		vis.addObject(Segment2(*p1, *p2), Color(1, 0, 0, 0.01));
		vis.addObject(Segment2(*p2, *p0), Color(1, 0, 0, 0.01));
	}
#endif
	// Finally, write the postscript file to disk!
	vis.writeFile();
}


void CMeshCreation::DoCDT()
{
	ConstraintGraph2* pConstraint = dt.createConstraint(vSegments, CIS_KEEP_DELAUNAY);
	
	Zone2* zone = dt.createZone(pConstraint, ZL_INSIDE);

	dt.applyConstraintsAndZones();
	customVisualization(zone, "example6b.ps");
	dt.refine(zone, 0.6f, 0.25f, 0.5f, true);
	customVisualization(zone, "example6b.ps");
	

	// Retrieve the triangles of the triangulation. Draw them in black
	std::vector<Triangle2*> vAllDelaunayTriangles;
	dt.getTrianglePointers(vAllDelaunayTriangles);
	for (std::vector<Triangle2*>::iterator it = vAllDelaunayTriangles.begin(); it != vAllDelaunayTriangles.
		end(); ++it)
	{
		Triangle2* t(*it);
		Point2* p0 = t->getCorner(0);
		Point2* p1 = t->getCorner(1);
		Point2* p2 = t->getCorner(2);
	}
}