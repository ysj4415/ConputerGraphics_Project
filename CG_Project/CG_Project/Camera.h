#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include "Transform.h"

class Camera
{
private:
	glm::vec3 cameraPos;		 //--- 카메라 위치
	glm::vec3 cameraDirection; //--- 카메라 바라보는 방향
	glm::vec3 cameraUp;		 //--- 카메라 위쪽 방향

	glm::mat4 view;			//뷰잉 매트릭스

public:
	Transform transform;
public:
	Camera();
	Camera(glm::vec3 CPos, glm::vec3 CDir, glm::vec3 CUp);
	~Camera();

	glm::mat4 GetMat();
};