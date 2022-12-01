#include "GameWorld.h"

glm::vec3 cameraPos = glm::vec3(1.0, 1.0, 1.0);		 //--- 카메라 위치
glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- 카메라 바라보는 방향
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);		 //--- 카메라 위쪽 방향

Camera camera(cameraPos, cameraDirection, cameraUp);
Projection_pres projection;
Mesh cube;