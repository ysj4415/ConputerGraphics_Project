#define _CRT_SECURE_NO_WARNINGS

#include "GameWorld.h"

GameWorld gameworld;

GameWorld::GameWorld()
{
	int tilenum = 0;

	glm::vec3 cameraPos = glm::vec3(0.0, 20.0, 0.0);		 //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, -1.0f);		 //--- 카메라 위쪽 방향

	camera.SetCamera(cameraPos, cameraDirection, cameraUp);
	ball = new Ball;
	AddObjectBuf(ball);
}
GameWorld::~GameWorld(){}

void GameWorld::AddObjectBuf(Actor* object)
{
	if (object_buf == NULL)
	{
		object_buf = object;
	}
	else
	{
		Actor* buf = object_buf;
		while (buf->nextobject != NULL)
		{
			buf = buf->nextobject;
		}
		buf->nextobject = object;
	}
}
void GameWorld::InitBuffer()
{
	Actor* buf = object_buf;

	while (buf != NULL)
	{
		buf->InitBuffer();
		buf = buf->nextobject;
	}
}
void GameWorld::Draw()
{
	Actor* buf = object_buf;

	while (buf != NULL)
	{
		buf->Draw(camera.GetMat(), projection.GetMat());
		buf = buf->nextobject;
	}
}
void GameWorld::Update()
{
	Actor* buf = object_buf;

	while (buf != NULL)
	{
		buf->Update();
		buf = buf->nextobject;
	}

	glm::vec3 ballPos = ball->transform.GetTrans();
	camera.CameraMoving(ballPos.x, ballPos.y, ballPos.z);
}

void GameWorld::CheckInTile()
{
	glm::vec4 SubBallLoc = ball->GetSubBallLoc();

	Tile* buf = tile;

	for (int i = 0; i < ball->tilecount + 1; i++)
	{
		buf = buf->nexttile;
	}
	if (buf != NULL && buf->CheckInBox(SubBallLoc.x, SubBallLoc.z) == true)
	{
		ball->ChangeBalls(buf->transform.GetTrans().x, buf->transform.GetTrans().z);
	}
}

void GameWorld::DataRead(const char* datafile)
{
	FILE* dataFile;
	dataFile = fopen(datafile, "rb");

	//--- 1. 전체 버텍스 개수 및 삼각형 개수 세기
	char count[100];

	while (!feof(dataFile)) {
		fscanf(dataFile, "%s", count);
		if (count[0] == 't' && count[1] == '\0')
			tilenum += 1;

		memset(count, '\0', sizeof(count)); // 배열 초기화
	}
	//--- 2. 메모리 할당
	glm::vec3 tiledata = glm::vec3(0.0, 0.0, 0.0);

	rewind(dataFile);

	//--- 3. 할당된 메모리에 각 버텍스, 페이스 정보 입력
	while (!feof(dataFile)) {
		fscanf(dataFile, "%s", count);
		if (count[0] == 't' && count[1] == '\0') {
			fscanf(dataFile, "%f %f %f",
				&tiledata.x, &tiledata.y, &tiledata.z);
			Tile* temp = new Tile(tiledata.x, tiledata.y, tiledata.z);
			Tile* buf = tile;
			if (buf == NULL) //buf가 비어있으면 buf에 삽입
			{
				tile = temp;
			}
			else             //비어있지 않으면 마지막 buf의 nexttile에 삽입
			{
				while (buf->nexttile != NULL)
				{
					buf = buf->nexttile;
				}
				buf->nexttile = temp;
			}
			AddObjectBuf(temp);
		}
	}

	fclose(dataFile);
}