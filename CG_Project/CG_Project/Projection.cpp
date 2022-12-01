#include "Projection.h"

Projection_ortho::Projection_ortho()
{
	projection = glm::mat4(1.0f);

	o_left = -50;
	o_right = 50;
	o_bottom = -50;
	o_top = 50;
	o_near = -50;
	o_far = 50;

	projection = glm::ortho(o_left, o_right, o_bottom, o_top, o_near, o_far);
}
Projection_ortho::Projection_ortho(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f)
{
	projection = glm::mat4(1.0f);

	o_left = l;
	o_right = r;
	o_bottom = b;
	o_top = t;
	o_near = n;
	o_far = f;

	projection = glm::ortho(o_left, o_right, o_bottom, o_top, o_near, o_far);
}
void Projection_ortho::SetProjection(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f)
{
	projection = glm::mat4(1.0f);

	o_left = l;
	o_right = r;
	o_bottom = b;
	o_top = t;
	o_near = n;
	o_far = f;

	projection = glm::ortho(o_left, o_right, o_bottom, o_top, o_near, o_far);
}
Projection_ortho::~Projection_ortho() {}
glm::mat4 Projection_ortho::GetMat() { return projection; }




Projection_pres::Projection_pres()
{
	projection = glm::mat4(1.0f);

	p_fovy = 45.0f;
	p_aspect = 1.0f;
	p_near = 0.1f;
	p_far = 100.0f;

	push_range = 1.0f;

	projection = glm::perspective(glm::radians(p_fovy), p_aspect, p_near, p_far);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -push_range)); //--- °ø°£À» ¾à°£ µÚ·Î ¹Ì·ïÁÜ
}
Projection_pres::Projection_pres(GLfloat fovy, GLfloat a, GLfloat n, GLfloat f, GLfloat pr)
{
	projection = glm::mat4(1.0f);

	p_fovy = fovy;
	p_aspect = a;
	p_near = n;
	p_far = f;

	push_range = pr;

	projection = glm::perspective(glm::radians(p_fovy), p_aspect, p_near, p_far);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -push_range)); //--- °ø°£À» ¾à°£ µÚ·Î ¹Ì·ïÁÜ
}
void Projection_pres::SetProjection(GLfloat fovy, GLfloat a, GLfloat n, GLfloat f, GLfloat pr)
{
	projection = glm::mat4(1.0f);

	p_fovy = fovy;
	p_aspect = a;
	p_near = n;
	p_far = f;

	push_range = pr;

	projection = glm::perspective(glm::radians(p_fovy), p_aspect, p_near, p_far);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -push_range)); //--- °ø°£À» ¾à°£ µÚ·Î ¹Ì·ïÁÜ
}
Projection_pres::~Projection_pres() {}
glm::mat4 Projection_pres::GetMat() { return projection; }