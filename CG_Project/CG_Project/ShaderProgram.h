#pragma once


#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include "filetobuf.h"



//void make_vertexShader();
//void make_fragmentShader();
//void InitShader();

class ShaderProgram
{
private:
	GLchar* vertexsource, * fragmentsource;		//---�ҽ��ڵ� ���� ����
	GLuint vertexshader, fragmentshader;		//---���̴� ��ü

	//---���̴� ���α׷�
	GLuint s_program;
public:
	ShaderProgram() {}
	~ShaderProgram() {}

};