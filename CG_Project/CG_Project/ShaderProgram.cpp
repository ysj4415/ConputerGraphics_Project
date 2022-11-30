#define _CRT_SECURE_NO_WARNINGS
#include "ShaderProgram.h"
#include "filetobuf.h"


//void make_vertexShader()
//{
//	vertexsource = filetobuf("vertex.glsl");
//
//
//	//--- 버텍스 세이더 객체 만들기
//	vertexshader = glCreateShader(GL_VERTEX_SHADER);
//
//	//--- 세이더 코드를 세이더 객체에 넣기
//	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
//
//	//--- 버텍스 세이더 컴파일하기
//	glCompileShader(vertexshader);
//
//	//--- 컴파일이 제대로 되지 않은 경우: 에러 체크
//	GLint result;
//	GLchar errorLog[512];
//	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(vertexshader, 512, NULL, errorLog);
//		std::cerr << "ERROR: vertex shader 컴파일 실패\n" << errorLog << std::endl;
//		return;
//	}
//
//}
//void make_fragmentShader()
//{
//	fragmentsource = filetobuf("fragment.glsl");
//
//
//	//--- 프래그먼트 세이더 객체 만들기
//	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//--- 세이더 코드를 세이더 객체에 넣기
//	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);
//
//	//--- 프래그먼트 세이더 컴파일
//	glCompileShader(fragmentshader);
//
//	//--- 컴파일이 제대로 되지 않은 경우: 컴파일 에러 체크
//	GLint result;
//	GLchar errorLog[512];
//	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(fragmentshader, 512, NULL, errorLog);
//		std::cerr << "ERROR: fragment shader 컴파일 실패\n" << errorLog << std::endl;
//		return;
//	}
//}
//
//
//
//void InitShader()
//{
//	make_vertexShader(); //--- 버텍스 세이더 만들기
//	make_fragmentShader(); //--- 프래그먼트 세이더 만들기
//	//-- shader Program
//	s_program = glCreateProgram();
//
//	glAttachShader(s_program, vertexshader);
//	glAttachShader(s_program, fragmentshader);
//
//	//--- 세이더 삭제하기
//
//	glDeleteShader(vertexshader);
//	glDeleteShader(fragmentshader);
//
//
//
//	// ---세이더가 잘 연결되었는지 체크하기
//	GLint result;
//	GLchar errorLog[512];
//	glGetProgramiv(s_program, GL_LINK_STATUS, &result);
//	if (!result) {
//		glGetProgramInfoLog(s_program, 512, NULL, errorLog);
//		std::cerr << "ERROR: shader program 연결 실패\n" << errorLog << std::endl;
//		return;
//	}
//}