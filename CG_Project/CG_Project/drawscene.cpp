#include "CallBack.h"
#include "Mesh.h"

extern Mesh cube;

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