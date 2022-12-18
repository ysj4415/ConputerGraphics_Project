#include "CallBack.h"
#include "Mesh.h"
#include "GameWorld.h"
#include "WindowState.h"
#include "ShaderProgram.h"

GLvoid drawScene()
{
	//---배경 초기화
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gameworld.Draw();
	glutSwapBuffers();
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		glutDestroyWindow(windowID);
		break;
	case ' ':
		gameworld.CheckInTile();
		break;
	}

	glutPostRedisplay();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

GLvoid TimerFunction(int value)
{
	if (value == 0)
	{
		gameworld.Update();
		glutTimerFunc(10, TimerFunction, 0);
	}

	glutPostRedisplay();
}

GLvoid SpecialKeyboard(int key, int x, int y)
{

}