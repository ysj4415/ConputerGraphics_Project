#include "Camera.h"

Camera::Camera()
{
	cameraPos = glm::vec3(0.0, 0.0, 1.0);		
	cameraDirection = glm::vec3(0.0, 0.0, 0.0);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);		

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
}
Camera::Camera(glm::vec3 CPos, glm::vec3 CDir, glm::vec3 CUp)
{
	cameraPos = CPos;
	cameraDirection = CDir;
	cameraUp = CUp;

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
}

Camera::~Camera() {}

glm::mat4 Camera::GetMat()
{
	return transform.GetMat() * view;
}