#include "CallBack.h"
#include "WindowState.h"

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		glutDestroyWindow(windowID);
		break;
	}

	glutPostRedisplay();
}