#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>


extern GLchar* vertexsource, * fragmentsource;		//---�ҽ��ڵ� ���� ����
extern GLuint vertexshader, fragmentshader;		//---���̴� ��ü

//---���̴� ���α׷�
extern GLuint s_program;

extern GLchar* Tvertexsource, * Tfragmentsource;		//---�ҽ��ڵ� ���� ����
extern GLuint Tvertexshader, Tfragmentshader;		//---���̴� ��ü

//---���̴� ���α׷�
extern GLuint Ts_program;

void make_vertexShader();
void make_fragmentShader();
void InitShader();
char* filetobuf(const char* file);
