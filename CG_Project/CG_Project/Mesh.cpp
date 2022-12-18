#include "Mesh.h"
#include "objReader.h"
#include "ShaderProgram.h"
#include "UserDefinedFunction.h"
//--------Mesh Function____________
Mesh::Mesh()
{
	vao = 0; vbo = 0; ebo = 0;
	vertexNum = 0;
	faceNum = 0;
	color = glm::vec3(0.0, 0.0, 0.0);
}
Mesh::~Mesh() {}

void Mesh::Draw(glm::mat4 view, glm::mat4 projection)
{
	glUseProgram(s_program);

	unsigned int viewLoc = glGetUniformLocation(s_program, "view"); //--- ºäÀ× º¯È¯ ¼³Á¤
	unsigned int projLoc = glGetUniformLocation(s_program, "projection");
	unsigned int modelLoc = glGetUniformLocation(s_program, "model");
	int vColorLocation = glGetUniformLocation(s_program, "vColor");

	glm::mat4 TR = transform.GetMat();

	glBindVertexArray(vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR));
	glUniform4f(vColorLocation, color.x, color.y, color.z, 1.0f);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection[0][0]);

	glDrawElements(GL_TRIANGLES, faceNum * 3, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0));
}


void Mesh::InitBuffer(const char* objname)
{
	obj objfile(objname);
	objfile.ReadObj();

	vertexNum = objfile.vertexNum;
	faceNum = objfile.faceNum;

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

void Mesh::SetColor(GLfloat r, GLfloat g, GLfloat b)
{
	color = glm::vec3(r, g, b);
}
glm::vec3 Mesh::GetColor()
{
	return color;
}
int Mesh::GetfaceNum()
{
	return faceNum;
}

//--------Line Function____________
Line::Line()
{
	vao = 0; vbo = 0;
	vertexNum = 0;
	color = glm::vec3(0.0, 0.0, 0.0);
}
Line::~Line() {}
void Line::InitBuffer(int pointnum, GLfloat radius)
{
	GLfloat* vertex = MakeCircle(pointnum, radius);

	vertexNum = pointnum;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexNum * 3 * sizeof(GLfloat), vertex, GL_STATIC_DRAW);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	glEnable(GL_DEPTH_TEST);

	delete vertex;
}

void Line::SetColor(GLfloat r, GLfloat g, GLfloat b)
{
	color = glm::vec3(r, g, b);
}
glm::vec3 Line::GetColor()
{
	return color;
}

int Line::GetVertexNum()
{
	return vertexNum;
}

//--------Actor Function____________
Actor::Actor()
{
	mesh.SetColor(1.0, 0.0, 0.0);
	nextobject = NULL;
}
Actor::~Actor() {}

void Actor::Draw(glm::mat4 view, glm::mat4 projection)
{
	glUseProgram(s_program);

	unsigned int viewLoc = glGetUniformLocation(s_program, "view"); //--- ºäÀ× º¯È¯ ¼³Á¤
	unsigned int projLoc = glGetUniformLocation(s_program, "projection");
	unsigned int modelLoc = glGetUniformLocation(s_program, "model");
	int vColorLocation = glGetUniformLocation(s_program, "vColor");

	glm::mat4 ObjectTR = transform.GetMat();
	glm::mat4 TR = ObjectTR * mesh.transform.GetMat();

	glBindVertexArray(mesh.vao);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(TR));
	glUniform4f(vColorLocation, mesh.GetColor().x, mesh.GetColor().y, mesh.GetColor().z, 1.0f);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection[0][0]);

	glDrawElements(GL_TRIANGLES, mesh.GetfaceNum() * 3, GL_UNSIGNED_INT, (GLvoid*)(sizeof(GLuint) * 0));
}
void Actor::Update() {}

void Actor::InitBuffer() {}
