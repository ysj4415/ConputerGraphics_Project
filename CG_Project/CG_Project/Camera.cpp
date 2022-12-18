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
void Camera::SetCamera(glm::vec3 CPos, glm::vec3 CDir, glm::vec3 CUp)
{
	cameraPos = CPos;
	cameraDirection = CDir;
	cameraUp = CUp;

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
}
Camera::~Camera() {}

glm::mat4 Camera::GetMat()
{
	return view;
}

void Camera::CameraMoving(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat cx = transform.GetTrans().x;
	GLfloat cy = transform.GetTrans().y;
	GLfloat cz = transform.GetTrans().z;

	//카메라가 해당 위치에 있지 않으면
	if (cx != x || cy != y || cz != z)
	{
		cx += (x - cx) * (1.0 / 20);
		cy += (y - cy) * (1.0 / 20);
		cz += (z - cz) * (1.0 / 20);

		transform.SetTrans(cx, cy, cz);
	}
	TransUpdate();
}

void Camera::TransUpdate()
{
	glm::vec4 c_pos_vec4 = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0);
	glm::vec4 c_dir_vec4 = glm::vec4(cameraDirection.x, cameraDirection.y, cameraDirection.z, 1.0);

	c_pos_vec4 = transform.GetMat() * c_pos_vec4;
	c_dir_vec4 = transform.GetMat() * c_dir_vec4;

	glm::vec3 c_pos_vec3 = glm::vec3(c_pos_vec4.x, c_pos_vec4.y, c_pos_vec4.z);
	glm::vec3 c_dir_vec3 = glm::vec3(c_dir_vec4.x, c_dir_vec4.y, c_dir_vec4.z);

	view = glm::lookAt(c_pos_vec3, c_dir_vec3, cameraUp);
}