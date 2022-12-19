#pragma once

#include "AllHeader.h"
#include "Mesh.h"

class Tile : public Actor
{
public:
	int type;
	Tile* nexttile = NULL;
public:
	Tile(GLfloat x, GLfloat y, GLfloat z, int t);
	~Tile();
	void InitBuffer();

	void Update();
	bool CheckInBox(GLfloat x, GLfloat z);
};