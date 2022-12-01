#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>



class Mesh
{
private:
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	glm::vec3 translate;
	glm::vec3 rotate;
	glm::vec3 scale;
public:

	Mesh();
	~Mesh();
	void InitBuffer();

	void Draw(glm::mat4 view, glm::mat4 projection);
};
