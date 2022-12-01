#include "CallBack.h"
#include "Mesh.h"
#include "GameWorld.h"

extern Mesh cube;

GLvoid drawScene()
{
	//---��� �ʱ�ȭ
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cube.Draw(camera.GetMat(), projection.GetMat());

	glutSwapBuffers();
}