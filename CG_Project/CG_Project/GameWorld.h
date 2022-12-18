#pragma once
#include "Camera.h"
#include "Mesh.h"
#include "Projection.h"
#include "Ball.h"
#include "Tile.h"

class GameWorld
{
private:
	int tilenum;
public:
	Camera camera;
	Projection_pres projection;
	Ball* ball;
	Tile* tile;
	Actor* object_buf;

public:
	GameWorld();
	~GameWorld();
	void AddObjectBuf(Actor* object);
	void InitBuffer();
	void Draw();
	void Update();
	void CheckInTile();
	void DataRead(const char* datafile);
};

extern GameWorld gameworld;
