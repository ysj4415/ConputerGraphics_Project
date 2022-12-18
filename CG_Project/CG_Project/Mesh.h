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
	//GLuint vao;
	//GLuint vbo;
	//GLuint ebo;

	int vertexNum;
	int faceNum;

	glm::vec3 color;

public:
	Transform transform;
	GLuint vao;
	GLuint vbo;
	GLuint ebo;
public:
	Mesh();
	~Mesh();
	void InitBuffer(const char* objname);
	void SetColor(GLfloat r, GLfloat g, GLfloat b);
	glm::vec3 GetColor();
	int GetfaceNum();

	void Draw(glm::mat4 view, glm::mat4 projection);
};

class Line
{
private:
	int vertexNum;

	glm::vec3 color;
public:
	Transform transform;
	GLuint vao;
	GLuint vbo;
public:
	Line();
	~Line();
	void InitBuffer(int pointspot, GLfloat radius);
	void SetColor(GLfloat r, GLfloat g, GLfloat b);
	glm::vec3 GetColor();
	int GetVertexNum();
};

class Actor
{
public:
	Mesh mesh;
	Transform transform;

	Actor* nextobject;
public:
	Actor();
	virtual ~Actor();
	virtual void Draw(glm::mat4 view, glm::mat4 projection);
	virtual void InitBuffer();
	virtual void Update();
};