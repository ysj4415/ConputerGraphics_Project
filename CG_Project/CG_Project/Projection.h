#pragma once
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>

class Projection_ortho
{
private:
	GLfloat o_left;
	GLfloat o_right;
	GLfloat o_bottom;
	GLfloat o_top;
	GLfloat o_near;
	GLfloat o_far;

	glm::mat4 projection;

public:
	Projection_ortho();
	Projection_ortho(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
	~Projection_ortho();
	void SetProjection(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);

	glm::mat4 GetMat();
};

class Projection_pres
{
private:
	GLfloat p_fovy;
	GLfloat p_aspect;
	GLfloat p_near;
	GLfloat p_far;

	GLfloat push_range;

	glm::mat4 projection;

public:
	Projection_pres();
	Projection_pres(GLfloat fovy, GLfloat a, GLfloat n, GLfloat f, GLfloat pr);
	~Projection_pres();
	void SetProjection(GLfloat fovy, GLfloat a, GLfloat n, GLfloat f, GLfloat pr);
	glm::mat4 GetMat();
};