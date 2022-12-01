#include "CallBack.h"

GLvoid TimerFunction(int value)
{
	if (value == 0)
	{
		glutTimerFunc(10, TimerFunction, 0);
	}

	glutPostRedisplay();
}