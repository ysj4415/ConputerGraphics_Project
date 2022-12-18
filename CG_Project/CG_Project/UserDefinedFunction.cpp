#include "UserDefinedFunction.h"
#define PI 3.141592

GLfloat* MakeCircle(int pointnum, GLfloat radius)
{
	GLfloat* circle_vertex = new GLfloat[pointnum * 3];
	float increment = 360.0 / pointnum;
	for (int i = 0; i < pointnum; i++)
	{
		circle_vertex[i * 3] = radius * cos(increment * i * PI / 180);
		circle_vertex[i * 3 + 1] = 0;
		circle_vertex[i * 3 + 2] = -1 * radius * sin(increment * i * PI / 180);
	}

	return circle_vertex;
}

