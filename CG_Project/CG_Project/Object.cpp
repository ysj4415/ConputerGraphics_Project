#include "Object.h"
#include "ShaderProgram.h"

Actor::Actor()
{
	a = 0;
	//mesh.InitBuffer("orb.obj");
	//mesh.SetColor(1.0, 0.0, 0.0);
}
//Actor::~Actor() {}
//
//void Actor::Draw(glm::mat4 view, glm::mat4 projection)
//{
//	glUseProgram(s_program);
//
//	unsigned int viewLoc = glGetUniformLocation(s_program, "view"); //--- ºäÀ× º¯È¯ ¼³Á¤
//	unsigned int projLoc = glGetUniformLocation(s_program, "projection");
//	unsigned int modelLoc = glGetUniformLocation(s_program, "model");
//	int vColorLocation = glGetUniformLocation(s_program, "vColor");
//
//	glm::mat4 TR = mesh.transform.GetMat();
//
//	glBindVertexArray(mesh.vao);
//
//	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR));
//	glUniform4f(vColorLocation, mesh.GetColor().x, mesh.GetColor().x, mesh.GetColor().x, 1.0f);
//	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
//	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection[0][0]);
//
//	glDrawElements(GL_TRIANGLES, mesh.GetfaceNum() * 3, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0));
//}
