#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
struct obj
{
	FILE* objFile;
	glm::vec3* vertex = NULL;
	glm::vec3* vertex_texture = NULL;
	glm::vec3* vertex_normal = NULL;

	int* face_v = NULL;
	int* face_vt = NULL;
	int* face_vn = NULL;

	int vertexNum = 0;
	int vertex_nomalNum = 0;
	int vertex_textureNum = 0;
	int faceNum = 0;

	void ReadObj();
	obj(const char* s)
	{
		objFile = fopen(s, "rb");
	}
	obj()
	{
		objFile = NULL;
	}
	void OpenFile(const char* s)
	{
		objFile = fopen(s, "rb");
	}
};
