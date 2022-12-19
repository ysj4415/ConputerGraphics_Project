#pragma once
#include "Camera.h"
#include "Mesh.h"
#include "Projection.h"
#include "Ball.h"
#include "Tile.h"
#include "Light.h"
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#include "Texture.h"

class FrameWork
{
public:
	Camera camera;
	Projection_pres projection;
	Light light;

	FrameWork* next_state;
public:
	FrameWork();
	virtual ~FrameWork();
	virtual void InitBuffer();
	virtual void Draw();
	virtual void Update();
	virtual void DataRead();
	virtual void KeyEvent(unsigned char key);
	virtual void MouseEvent(int x, int y);
};


class GameWorld : public FrameWork
{
private:
	int tilenum;
public:
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
	void DataRead();
	void KeyEvent(unsigned char key);
	void MouseEvent(int x, int y);
};

class MainState : public FrameWork
{
public:
	Texture background;
	Texture start;

public:
	MainState();
	~MainState();
	void InitBuffer();
	void Draw();
	void Update();
	void KeyEvent(unsigned char key);
	void MouseEvent(int x, int y);
};

class StageState : public FrameWork
{
public:
	Texture background;
	Texture stage1;
	Texture stage2;

public:
	StageState();
	~StageState();
	void InitBuffer();
	void Draw();
	void Update();
	void KeyEvent(unsigned char key);
	void MouseEvent(int x, int y);
};

void NextState();


extern FrameWork* cur_state;
extern MainState* mainstate;


class GameWorld2 : public FrameWork
{
private:
	int tilenum;
public:
	Ball* ball;
	Tile* tile;
	Actor* object_buf;
public:
	GameWorld2();
	~GameWorld2();
	void AddObjectBuf(Actor* object);
	void InitBuffer();
	void Draw();
	void Update();
	void CheckInTile();
	void DataRead();
	void KeyEvent(unsigned char key);
	void MouseEvent(int x, int y);
};