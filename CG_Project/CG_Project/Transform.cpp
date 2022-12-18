#include "Transform.h"

Transform::Transform()
{
	translate = glm::vec3(0.0, 0.0, 0.0);
	rotate = glm::vec3(0.0, 0.0, 0.0);
	scale = glm::vec3(1.0, 1.0, 1.0);
}
Transform::Transform(glm::vec3 t, glm::vec3 r, glm::vec3 s)
{
	translate = t;
	rotate = r;
	scale = s;
}
Transform::~Transform() {}

void Transform::SetTrans(GLfloat x, GLfloat y, GLfloat z) { translate = glm::vec3(x, y, z); }
void Transform::SetRotate(GLfloat x, GLfloat y, GLfloat z) { rotate = glm::vec3(x, y, z); }
void Transform::SetScale(GLfloat x, GLfloat y, GLfloat z) { scale = glm::vec3(x, y, z); }

void Transform::Add_Trans(GLfloat x, GLfloat y, GLfloat z) { translate += glm::vec3(x, y, z); }
void Transform::Add_Rotate(GLfloat x, GLfloat y, GLfloat z) { rotate += glm::vec3(x, y, z); }
void Transform::Add_Scale(GLfloat x, GLfloat y, GLfloat z) { scale += glm::vec3(x, y, z); }

glm::mat4 Transform::GetMat()
{
	glm::mat4 TR = glm::mat4(1.0f);

	TR = glm::translate(TR, glm::vec3(translate.x, translate.y, translate.z));
	TR = glm::rotate(TR, (GLfloat)glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
	TR = glm::rotate(TR, (GLfloat)glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
	TR = glm::rotate(TR, (GLfloat)glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
	TR = glm::scale(TR, glm::vec3(scale.x, scale.y, scale.z));

	return TR;
}
glm::vec3 Transform::GetTrans()
{
	return translate;
}
glm::vec3 Transform::GetScale()
{
	return scale;
}
