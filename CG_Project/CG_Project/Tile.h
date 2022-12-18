#pragma once

#include "AllHeader.h"
#include "Mesh.h"

class Tile : public Actor
{
public:
	Tile* nexttile = NULL;
public:
	Tile(GLfloat x, GLfloat y, GLfloat z);
	~Tile();
	void InitBuffer();

	void Update();
	bool CheckInBox(GLfloat x, GLfloat z);
};