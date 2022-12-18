#include "Tile.h"

Tile::Tile(GLfloat x, GLfloat y, GLfloat z)
{
	mesh.SetColor(0.7, 0.7, 0.7);
	transform.SetScale(0.8, 0.2, 0.8);
	transform.SetTrans(x, y, z);
}
Tile::~Tile() {}
void Tile::InitBuffer()
{
	mesh.InitBuffer("cube.obj");
}
void Tile::Update() {}

bool Tile::CheckInBox(GLfloat x, GLfloat z)
{
	glm::vec3 pos = transform.GetTrans();

	GLfloat left = pos.x - 0.7;
	GLfloat right = pos.x + 0.7;
	GLfloat top = pos.z - 0.7f;
	GLfloat bottom = pos.z + 0.7f;
	std::cout << x << ", " << z << std::endl;
	if (left < x && right > x && top < z && bottom > z)
		return true;
	else return false;
}