#define _CRT_SECURE_NO_WARNINGS
#include "ShaderProgram.h"
#include "filetobuf.h"


//void make_vertexShader()
//{
//	vertexsource = filetobuf("vertex.glsl");
//
//
//	//--- ���ؽ� ���̴� ��ü �����
//	vertexshader = glCreateShader(GL_VERTEX_SHADER);
//
//	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
//	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
//
//	//--- ���ؽ� ���̴� �������ϱ�
//	glCompileShader(vertexshader);
//
//	//--- �������� ����� ���� ���� ���: ���� üũ
//	GLint result;
//	GLchar errorLog[512];
//	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(vertexshader, 512, NULL, errorLog);
//		std::cerr << "ERROR: vertex shader ������ ����\n" << errorLog << std::endl;
//		return;
//	}
//
//}
//void make_fragmentShader()
//{
//	fragmentsource = filetobuf("fragment.glsl");
//
//
//	//--- �����׸�Ʈ ���̴� ��ü �����
//	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
//
//	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
//	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);
//
//	//--- �����׸�Ʈ ���̴� ������
//	glCompileShader(fragmentshader);
//
//	//--- �������� ����� ���� ���� ���: ������ ���� üũ
//	GLint result;
//	GLchar errorLog[512];
//	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
//	if (!result)
//	{
//		glGetShaderInfoLog(fragmentshader, 512, NULL, errorLog);
//		std::cerr << "ERROR: fragment shader ������ ����\n" << errorLog << std::endl;
//		return;
//	}
//}
//
//
//
//void InitShader()
//{
//	make_vertexShader(); //--- ���ؽ� ���̴� �����
//	make_fragmentShader(); //--- �����׸�Ʈ ���̴� �����
//	//-- shader Program
//	s_program = glCreateProgram();
//
//	glAttachShader(s_program, vertexshader);
//	glAttachShader(s_program, fragmentshader);
//
//	//--- ���̴� �����ϱ�
//
//	glDeleteShader(vertexshader);
//	glDeleteShader(fragmentshader);
//
//
//
//	// ---���̴��� �� ����Ǿ����� üũ�ϱ�
//	GLint result;
//	GLchar errorLog[512];
//	glGetProgramiv(s_program, GL_LINK_STATUS, &result);
//	if (!result) {
//		glGetProgramInfoLog(s_program, 512, NULL, errorLog);
//		std::cerr << "ERROR: shader program ���� ����\n" << errorLog << std::endl;
//		return;
//	}
//}