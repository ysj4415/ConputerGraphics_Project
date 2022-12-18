#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>

class Transform
{
private:
	glm::vec3 translate;
	glm::vec3 rotate;
	glm::vec3 scale;
public:
	Transform();
	Transform(glm::vec3 t, glm::vec3 r, glm::vec3 s);

	~Transform();

	void SetTrans(GLfloat x, GLfloat y, GLfloat z);
	void SetRotate(GLfloat x, GLfloat y, GLfloat z);
	void SetScale(GLfloat x, GLfloat y, GLfloat z);
	glm::vec3 GetTrans();
	glm::vec3 GetScale();

	void Add_Trans(GLfloat x, GLfloat y, GLfloat z);
	void Add_Rotate(GLfloat x, GLfloat y, GLfloat z);
	void Add_Scale(GLfloat x, GLfloat y, GLfloat z);

	glm::mat4 GetMat();
};
