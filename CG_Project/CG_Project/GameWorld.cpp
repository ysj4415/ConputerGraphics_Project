#include "GameWorld.h"

glm::vec3 cameraPos = glm::vec3(1.0, 1.0, 1.0);		 //--- ī�޶� ��ġ
glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- ī�޶� �ٶ󺸴� ����
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);		 //--- ī�޶� ���� ����

Camera camera(cameraPos, cameraDirection, cameraUp);
Projection_pres projection;
Mesh cube;