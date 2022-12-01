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
	glm::vec3 cameraPos;		 //--- ī�޶� ��ġ
	glm::vec3 cameraDirection; //--- ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraUp;		 //--- ī�޶� ���� ����

	glm::mat4 view;			//���� ��Ʈ����

public:
	Transform transform;
public:
	Camera();
	Camera(glm::vec3 CPos, glm::vec3 CDir, glm::vec3 CUp);
	~Camera();

	glm::mat4 GetMat();
};