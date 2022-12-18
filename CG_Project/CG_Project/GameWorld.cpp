#define _CRT_SECURE_NO_WARNINGS

#include "GameWorld.h"

GameWorld gameworld;

GameWorld::GameWorld()
{
	int tilenum = 0;

	glm::vec3 cameraPos = glm::vec3(0.0, 20.0, 0.0);		 //--- ī�޶� ��ġ
	glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, -1.0f);		 //--- ī�޶� ���� ����

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

	//--- 1. ��ü ���ؽ� ���� �� �ﰢ�� ���� ����
	char count[100];

	while (!feof(dataFile)) {
		fscanf(dataFile, "%s", count);
		if (count[0] == 't' && count[1] == '\0')
			tilenum += 1;

		memset(count, '\0', sizeof(count)); // �迭 �ʱ�ȭ
	}
	//--- 2. �޸� �Ҵ�
	glm::vec3 tiledata = glm::vec3(0.0, 0.0, 0.0);

	rewind(dataFile);

	//--- 3. �Ҵ�� �޸𸮿� �� ���ؽ�, ���̽� ���� �Է�
	while (!feof(dataFile)) {
		fscanf(dataFile, "%s", count);
		if (count[0] == 't' && count[1] == '\0') {
			fscanf(dataFile, "%f %f %f",
				&tiledata.x, &tiledata.y, &tiledata.z);
			Tile* temp = new Tile(tiledata.x, tiledata.y, tiledata.z);
			Tile* buf = tile;
			if (buf == NULL) //buf�� ��������� buf�� ����
			{
				tile = temp;
			}
			else             //������� ������ ������ buf�� nexttile�� ����
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