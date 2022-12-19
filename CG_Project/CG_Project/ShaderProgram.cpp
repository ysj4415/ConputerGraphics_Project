#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable: 26451)
#include "ShaderProgram.h"

GLchar* vertexsource, * fragmentsource;		//---�ҽ��ڵ� ���� ����
GLuint vertexshader, fragmentshader;		//---���̴� ��ü

//---���̴� ���α׷�
GLuint s_program;

GLchar* Tvertexsource, * Tfragmentsource;		//---�ҽ��ڵ� ���� ����
GLuint Tvertexshader, Tfragmentshader;		//---���̴� ��ü

//---���̴� ���α׷�
GLuint Ts_program;

void make_vertexShader()
{
	vertexsource = filetobuf("vertex.glsl");

	//--- ���ؽ� ���̴� ��ü �����
	vertexshader = glCreateShader(GL_VERTEX_SHADER);

	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);

	//--- ���ؽ� ���̴� �������ϱ�
	glCompileShader(vertexshader);

	//--- �������� ����� ���� ���� ���: ���� üũ
	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader ������ ����\n" << errorLog << std::endl;
		return;
	}
	Tvertexsource = filetobuf("vertex_texure.glsl");

	//--- ���ؽ� ���̴� ��ü �����
	Tvertexshader = glCreateShader(GL_VERTEX_SHADER);

	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glShaderSource(Tvertexshader, 1, (const GLchar**)&Tvertexsource, 0);

	//--- ���ؽ� ���̴� �������ϱ�
	glCompileShader(Tvertexshader);

	//--- �������� ����� ���� ���� ���: ���� üũ

	glGetShaderiv(Tvertexshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(Tvertexshader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader ������ ����\n" << errorLog << std::endl;
		return;
	}
}
void make_fragmentShader()
{
	fragmentsource = filetobuf("fragment.glsl");


	//--- �����׸�Ʈ ���̴� ��ü �����
	fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);

	//--- �����׸�Ʈ ���̴� ������
	glCompileShader(fragmentshader);

	//--- �������� ����� ���� ���� ���: ������ ���� üũ
	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, errorLog);
		std::cerr << "ERROR: fragment shader ������ ����\n" << errorLog << std::endl;
		return;
	}
	Tfragmentsource = filetobuf("fragment_texture.glsl");


	//--- �����׸�Ʈ ���̴� ��ü �����
	Tfragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
	glShaderSource(Tfragmentshader, 1, (const GLchar**)&Tfragmentsource, 0);

	//--- �����׸�Ʈ ���̴� ������
	glCompileShader(Tfragmentshader);

	//--- �������� ����� ���� ���� ���: ������ ���� üũ

	glGetShaderiv(Tfragmentshader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(Tfragmentshader, 512, NULL, errorLog);
		std::cerr << "ERROR: fragment shader ������ ����\n" << errorLog << std::endl;
		return;
	}
}



void InitShader()
{
	make_vertexShader(); //--- ���ؽ� ���̴� �����
	make_fragmentShader(); //--- �����׸�Ʈ ���̴� �����
	//-- shader Program
	s_program = glCreateProgram();

	glAttachShader(s_program, vertexshader);
	glAttachShader(s_program, fragmentshader);

	//--- ���̴� �����ϱ�

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);

	glLinkProgram(s_program);

	// ---���̴��� �� ����Ǿ����� üũ�ϱ�
	GLint result;
	GLchar errorLog[512];
	glGetProgramiv(s_program, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(s_program, 512, NULL, errorLog);
		std::cerr << "ERROR: shader program ���� ����\n" << errorLog << std::endl;
		return;
	}



	make_vertexShader(); //--- ���ؽ� ���̴� �����
	make_fragmentShader(); //--- �����׸�Ʈ ���̴� �����
	//-- shader Program
	Ts_program = glCreateProgram();

	glAttachShader(Ts_program, Tvertexshader);
	glAttachShader(Ts_program, Tfragmentshader);

	//--- ���̴� �����ϱ�

	glDeleteShader(Tvertexshader);
	glDeleteShader(Tfragmentshader);

	glLinkProgram(Ts_program);

	// ---���̴��� �� ����Ǿ����� üũ�ϱ�

	glGetProgramiv(Ts_program, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(Ts_program, 512, NULL, errorLog);
		std::cerr << "ERROR: shader program ���� ����\n" << errorLog << std::endl;
		return;
	}
}

char* filetobuf(const char* file)
{
	FILE* fp;
	long length;
	char* buf;

	fp = fopen(file, "rb");

	if (!fp)
		assert(fp != nullptr);

	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	buf = (char*)malloc(sizeof(char) * length + 1);
	fseek(fp, 0, SEEK_SET);
	if (buf != nullptr)
		fread(buf, 1, length + 1, fp);

	fclose(fp);
	if (buf != nullptr)
		buf[length] = 0;

	return buf;
}