#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include "Transform.h"


class Mesh
{
private:
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	int vertexNum;
	int faceNum;

	glm::vec3 color;

public:
	Transform transform;

public:
	Mesh();
	~Mesh();
	void InitBuffer();
	void SetColor(GLfloat r, GLfloat g, GLfloat b);

	void Draw(glm::mat4 view, glm::mat4 projection);
};
