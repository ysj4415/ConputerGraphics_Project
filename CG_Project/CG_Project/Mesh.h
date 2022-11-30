#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>



class Mesh
{
private:
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	glm::vec3 translate;
	glm::vec3 rotate;
	glm::vec3 scale;
public:

	Mesh() 
	{
		translate = glm::vec3(0.0, 0.0, 0.0);
		rotate = glm::vec3(0.0, 0.0, 0.0);
		scale = glm::vec3(1.0, 1.0, 1.0);

	}
	~Mesh() {}
	void InitBuffer();

	void Draw(glm::mat4 view, glm::mat4 projection);
	//{
	//	InitBuffer();

	//	unsigned int viewLoc_shape = glGetUniformLocation(s_program, "view"); //--- ºäÀ× º¯È¯ ¼³Á¤
	//	unsigned int projLoc_shape = glGetUniformLocation(s_program, "projection");


	//	glUseProgram(s_program);
	//	glUniformMatrix4fv(viewLoc_shape, 1, GL_FALSE, &view[0][0]);
	//	glUniformMatrix4fv(projLoc_shape, 1, GL_FALSE, &projection[0][0]);

	//	unsigned int modelLoc = glGetUniformLocation(s_program, "model");
	//	int vColorLocation = glGetUniformLocation(s_program, "vColor");

	//	glm::mat4 TR_cube = glm::mat4(1.0f);

	//	TR_cube = glm::translate(TR_cube, glm::vec3(translate.x, translate.y, translate.z));
	//	TR_cube = glm::rotate(TR_cube, (GLfloat)glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
	//	TR_cube = glm::rotate(TR_cube, (GLfloat)glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
	//	TR_cube = glm::rotate(TR_cube, (GLfloat)glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
	//	TR_cube = glm::scale(TR_cube, glm::vec3(scale.x, scale.y, scale.z));

	//	glBindVertexArray(vao);

	//	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR_cube));
	//	glUniform4f(vColorLocation, 1.0, 0.0, 0.0, 1.0f);
	//	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0 * 6));
	//}
};
