#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>


extern GLchar* vertexsource, * fragmentsource;		//---소스코드 저장 변수
extern GLuint vertexshader, fragmentshader;		//---세이더 객체

//---쉐이더 프로그램
extern GLuint s_program;

void make_vertexShader();
void make_fragmentShader();
void InitShader();
char* filetobuf(const char* file);
