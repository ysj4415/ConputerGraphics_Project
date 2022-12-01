#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include <cmath>
#include "Mesh.h"
#include "ShaderProgram.h"


using namespace std;

//---윈도우 사이즈 변수
int WinSize_w = 800;
int WinSize_h = 800;
int windowID;		//---윈도우 아이디

//---콜백 함수
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
GLvoid TimerFunction(int value);

Mesh cube;

int main(int argc, char** argv)		//---윈도우 출력, 콜백함수 설정
{
	//---윈도우 생성
	glutInit(&argc, argv);		//glut초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	//디스플레이 모드 설정
	glutInitWindowPosition(0, 0);					//윈도우 위치 지정
	glutInitWindowSize(WinSize_w, WinSize_h);					//윈도우 크기 지정
	windowID = glutCreateWindow("Example1");					//윈도우 생성

	//---GLEW 초기화
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)		//glew 초기화에 실패할 경우
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW initialized\n";

	InitShader();

	cube.InitBuffer();
	glEnable(GL_DEPTH_TEST);


	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();
}


GLvoid drawScene()
{
	//---배경 초기화
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		
	glm::vec3 cameraPos = glm::vec3(0.0, 0.0, 1.0);		 //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);		 //--- 카메라 위쪽 방향

	glm::mat4 view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	

	//---투영변환
	glm::mat4 projection = glm::mat4(1.0f);

	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -1.0)); //--- 공간을 약간 뒤로 미뤄줌


	cube.Draw(view, projection);


	glutSwapBuffers();

}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

}

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		glutDestroyWindow(windowID);
		break;
	}

	glutPostRedisplay();
}


GLvoid TimerFunction(int value)
{
	if (value == 0)
	{
		glutTimerFunc(10, TimerFunction, 0);
	}

	glutPostRedisplay();
}






