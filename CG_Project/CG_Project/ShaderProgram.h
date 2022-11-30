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
	GLchar* vertexsource, * fragmentsource;		//---소스코드 저장 변수
	GLuint vertexshader, fragmentshader;		//---세이더 객체

	//---쉐이더 프로그램
	GLuint s_program;
public:
	ShaderProgram() {}
	~ShaderProgram() {}

};