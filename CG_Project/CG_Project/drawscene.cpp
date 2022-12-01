#include "CallBack.h"
#include "Mesh.h"

extern Mesh cube;

GLvoid drawScene()
{
	//---��� �ʱ�ȭ
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




	glm::vec3 cameraPos = glm::vec3(0.0, 0.0, 1.0);		 //--- ī�޶� ��ġ
	glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);		 //--- ī�޶� ���� ����

	glm::mat4 view = glm::lookAt(cameraPos, cameraDirection, cameraUp);


	//---������ȯ
	glm::mat4 projection = glm::mat4(1.0f);

	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -1.0)); //--- ������ �ణ �ڷ� �̷���


	cube.Draw(view, projection);


	glutSwapBuffers();

}