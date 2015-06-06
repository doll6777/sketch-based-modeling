#include <vgl.h>
#include <stdio.h>
#include <vec.h>
#include <list>
#include "Mesh.h"
#include "Drawing.h"
#include "SceneManager.h"

using namespace std;

// Convert ScreenCoord -> -1 ~ 1
#define ConvertSWidth(x,l) x / (l / 2.0f) - 1
#define ConvertSHeight(x,l) 1 - x / (l / 2.0f)

bool bMouseMoving = false;

// SingleTon
CSceneManager *sceneManager;
std::list<CVertex> li;

void myDisplay()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw Path
	glColor3f(0, 0, 0);
	sceneManager->DrawTool.DrawPolygon(sceneManager->GetPointList());
	
	glColor3f(1, 0, 0);

	// Draw Coarse Path
	sceneManager->DrawTool.DrawPolygon(li);

	glutSwapBuffers();
	glutPostRedisplay();
}

// Mouse Clicked
void myMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		float fx = ConvertSWidth(x, sceneManager->screenWidth);
		float fy = ConvertSHeight(y, sceneManager->screenHeight);

		sceneManager->PushPointList(CVertex(vec3(fx, fy,0)));
		bMouseMoving = true;
	}

	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		bMouseMoving = false;
		li = sceneManager->MeshCreation.InitPolygon(sceneManager->GetPointList());
		sceneManager->MeshCreation.DoCDT();
	}
	glutPostRedisplay();
	
}

// Mouse Moving
void myMouseMove(int x, int y)
{
	if (bMouseMoving)
	{
		float fx = ConvertSWidth(x, sceneManager->screenWidth);
		float fy = ConvertSHeight(y, sceneManager->screenHeight);

		sceneManager->PushPointList(CVertex(vec3(fx, fy,0)));
	}
	glutPostRedisplay();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

// Get Singleton Instance
void SceneInit()
{
	sceneManager = CSceneManager::GetPointer();
}

int main(int argc, char** argv)
{
	SceneInit();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(sceneManager->screenWidth, sceneManager->screenHeight);
	glutCreateWindow("TeddyTest");

	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMotionFunc(myMouseMove);
	glutMouseFunc(myMouseClick);

	glutMainLoop();

	return 0;
}