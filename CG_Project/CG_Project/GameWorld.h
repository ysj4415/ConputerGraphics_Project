#pragma once
#include "Camera.h"
#include "Mesh.h"
#include "Projection.h"
#include "Ball.h"
#include "Tile.h"
#include "Light.h"

class GameWorld
{
private:
	int tilenum;
public:
	Camera camera;
	Projection_pres projection;
	Light light;
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
