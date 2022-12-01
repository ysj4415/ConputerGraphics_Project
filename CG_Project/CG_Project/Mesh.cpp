#include "Mesh.h"
#include "objReader.h"
#include "ShaderProgram.h"

Mesh::Mesh()
{
	vao = 0; vbo = 0; ebo = 0;
	translate = glm::vec3(0.0, 0.0, 0.0);
	rotate = glm::vec3(0.0, 0.0, 0.0);
	scale = glm::vec3(2.0, 1.0, 1.0);
}
Mesh::~Mesh() {}

void Mesh::Draw(glm::mat4 view, glm::mat4 projection)
{
	glUseProgram(s_program);

	unsigned int viewLoc_shape = glGetUniformLocation(s_program, "view"); //--- ºäÀ× º¯È¯ ¼³Á¤
	unsigned int projLoc_shape = glGetUniformLocation(s_program, "projection");

	glUniformMatrix4fv(viewLoc_shape, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projLoc_shape, 1, GL_FALSE, &projection[0][0]);

	unsigned int modelLoc = glGetUniformLocation(s_program, "model");
	int vColorLocation = glGetUniformLocation(s_program, "vColor");

	glm::mat4 TR_cube = glm::mat4(1.0f);

	TR_cube = glm::translate(TR_cube, glm::vec3(translate.x, translate.y, translate.z));
	TR_cube = glm::rotate(TR_cube, (GLfloat)glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
	TR_cube = glm::rotate(TR_cube, (GLfloat)glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
	TR_cube = glm::rotate(TR_cube, (GLfloat)glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
	TR_cube = glm::scale(TR_cube, glm::vec3(scale.x, scale.y, scale.z));

	glBindVertexArray(vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR_cube));
	glUniform4f(vColorLocation, 1.0, 0.0, 0.0, 1.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0 * 6));
}


void Mesh::InitBuffer()
{
	obj objfile("cube.obj");
	objfile.ReadObj();

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, objfile.vertexNum * 3 * sizeof(GLfloat), objfile.vertex, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, objfile.faceNum * 3 * sizeof(int), objfile.face_v, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	glEnable(GL_DEPTH_TEST);
}