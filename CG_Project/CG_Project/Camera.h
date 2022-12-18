#pragma once
#include "AllHeader.h"
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
	void SetCamera(glm::vec3 CPos, glm::vec3 CDir, glm::vec3 CUp);
	~Camera();

	glm::mat4 GetMat();
	void CameraMoving(GLfloat x, GLfloat y, GLfloat z);		//ī�޶� ���� ��ġ�� ���󰡰�
	void TransUpdate();			//ī�޶� ��ȯ �ݿ�
};