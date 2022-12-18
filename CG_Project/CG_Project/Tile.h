#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include "Mesh.h"

class Tile : public Actor
{
public:
	Tile* nexttile = NULL;
public:
	Tile(GLfloat x, GLfloat y, GLfloat z);
	~Tile();
	void InitBuffer();

	void Update();
	bool CheckInBox(GLfloat x, GLfloat z);
};