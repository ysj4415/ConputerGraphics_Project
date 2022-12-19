#define _CRT_SECURE_NO_WARNINGS

#include "WindowState.h"
#include "GameWorld.h"

FrameWork* cur_state = NULL;
MainState* mainstate = new MainState;

//-----------------프레임워크
FrameWork::FrameWork() { next_state == NULL; }
FrameWork::~FrameWork() {}
void FrameWork::InitBuffer() {}
void FrameWork::Draw() {}
void FrameWork::Update() {}
void FrameWork::DataRead() {}
void FrameWork::KeyEvent(unsigned char key) {}
void FrameWork::MouseEvent(int x, int y) {}
//--------------------게임월드

GameWorld::GameWorld()
{
	int tilenum = 0;

	glm::vec3 cameraPos = glm::vec3(0.0, 20.0, 0.0);		 //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, -1.0f);		 //--- 카메라 위쪽 방향

	camera.SetCamera(cameraPos, cameraDirection, cameraUp);
	ball = new Ball;
	AddObjectBuf(ball);

	PlaySound(TEXT("stage1.wav"), NULL, SND_ASYNC | SND_LOOP);
}
GameWorld::~GameWorld(){ PlaySound(NULL, 0, 0); }

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

	NextState();

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
		if (ball->tilecount == 0)
		{
			tile->mesh.SetColor(1.0, 1.0, 1.0);
		}
		buf->mesh.SetColor(1.0, 1.0, 1.0);
		ball->ChangeBalls(buf->transform.GetTrans().x, buf->transform.GetTrans().z);
	}
	std::cout << tilenum << std::endl;
	if (ball->tilecount + 1 == tilenum)
	{
		MainState* mainstate = new MainState;
		next_state = mainstate;
		NextState();
	}
}
void GameWorld::KeyEvent(unsigned char key) 
{
	bool gotoMain = false;
	switch (key)
	{
	case 'q':
		gotoMain = true;
		break;
	case ' ':
		CheckInTile();
		break;
	}
	if (gotoMain == true)
	{
		MainState* mainstate = new MainState;
		next_state = mainstate;
		NextState();
	}

}
void GameWorld::MouseEvent(int x, int y) {}
void GameWorld::DataRead()
{
	FILE* dataFile;
	dataFile = fopen("ObjectData.data", "rb");

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

//-----------메인스테이트

MainState::MainState() 
{
	background.transform.SetTrans(0.0, 0.2, 0.0);
	start.transform.SetTrans(0.0, -0.6, 0.0);
	start.transform.SetScale(0.6, 0.3, 1.0);

}
MainState::~MainState() 
{
}
void MainState::InitBuffer() 
{
	background.initBuffer();
	background.InitTexture("fire.jpg");
	start.initBuffer();
	start.InitTexture("start.jpg");
}
void MainState::Draw() 
{
	background.Draw();
	start.Draw();
}
void MainState::Update() {}
void MainState::KeyEvent(unsigned char key)
{
	switch (key)
	{
	case 'q':
		glutDestroyWindow(windowID);
		break;
	}
}
void MainState::MouseEvent(int x, int y)
{
	GLfloat mx = ((GLfloat)x - (GLfloat)WinSize_w / 2) / WinSize_w * 2;
	GLfloat my = ((GLfloat)WinSize_h / 2 - (GLfloat)y ) / WinSize_h * 2;

	if (mx > -0.3 && mx < 0.3 && my > -0.75 && my < -0.45)
	{
		StageState* stagestate = new StageState;
		next_state = stagestate;
		NextState();
	}
}

//-----------스테이지스테이트

StageState::StageState()
{
	background.transform.SetTrans(0.0, 0.2, 0.0);
	stage1.transform.SetTrans(-0.6, -0.6, 0.0);
	stage1.transform.SetScale(0.3, 0.3, 1.0);
	stage2.transform.SetTrans(0.0, -0.6, 0.0);
	stage2.transform.SetScale(0.3, 0.3, 1.0);
}
StageState::~StageState() {}
void StageState::InitBuffer()
{
	background.initBuffer();
	background.InitTexture("fire.jpg");
	stage1.initBuffer();
	stage1.InitTexture("1.jpg");
	stage2.initBuffer();
	stage2.InitTexture("2.jpg");
}
void StageState::Draw()
{
	background.Draw();
	stage1.Draw();
	stage2.Draw();
}
void StageState::Update() {}
void StageState::KeyEvent(unsigned char key)
{
	switch (key)
	{
	case 'q':
		MainState * mainstate = new MainState;
		next_state = mainstate;
		NextState();
		break;
	}
}
void StageState::MouseEvent(int x, int y)
{
	GLfloat mx = ((GLfloat)x - (GLfloat)WinSize_w / 2) / WinSize_w * 2;
	GLfloat my = ((GLfloat)WinSize_h / 2 - (GLfloat)y) / WinSize_h * 2;

	if (mx < -0.45 && mx > - 0.75 &&  my > -0.75 && my < -0.45)
	{
		GameWorld* gameworld = new GameWorld;
		next_state = gameworld;
		NextState();
	}
	else if (mx > -0.15 && mx < 0.15 && my > -0.75 && my < -0.45)
	{
		GameWorld2* gameworld2 = new GameWorld2;
		next_state = gameworld2;
		NextState();
	}
}



void NextState()
{
	if (cur_state->next_state != NULL)
	{
		FrameWork* Temp = cur_state;
		cur_state = cur_state->next_state;
		delete Temp;

		cur_state->DataRead();
		cur_state->light.Setting();
		cur_state->InitBuffer();
	}


}
//--------------------게임월드2

GameWorld2::GameWorld2()
{
	int tilenum = 0;

	glm::vec3 cameraPos = glm::vec3(0.0, 20.0, 0.0);		 //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0, 0.0, 0.0); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, -1.0f);		 //--- 카메라 위쪽 방향

	camera.SetCamera(cameraPos, cameraDirection, cameraUp);
	ball = new Ball;
	AddObjectBuf(ball);

	PlaySound(TEXT("stage2.wav"), NULL, SND_ASYNC | SND_LOOP);
}
GameWorld2::~GameWorld2() { PlaySound(NULL, 0, 0); }

void GameWorld2::AddObjectBuf(Actor* object)
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
void GameWorld2::InitBuffer()
{
	Actor* buf = object_buf;

	while (buf != NULL)
	{
		buf->InitBuffer();
		buf = buf->nextobject;
	}
}
void GameWorld2::Draw()
{
	Actor* buf = object_buf;

	while (buf != NULL)
	{
		buf->Draw(camera.GetMat(), projection.GetMat());
		buf = buf->nextobject;
	}
}
void GameWorld2::Update()
{
	Actor* buf = object_buf;

	while (buf != NULL)
	{
		buf->Update();
		buf = buf->nextobject;
	}

	glm::vec3 ballPos = ball->transform.GetTrans();
	camera.CameraMoving(ballPos.x, ballPos.y, ballPos.z);

	NextState();

}

void GameWorld2::CheckInTile()
{
	glm::vec4 SubBallLoc = ball->GetSubBallLoc();

	Tile* buf = tile;

	for (int i = 0; i < ball->tilecount + 1; i++)
	{
		buf = buf->nexttile;
	}
	if (buf != NULL && buf->CheckInBox(SubBallLoc.x, SubBallLoc.z) == true)
	{
		if (ball->tilecount == 0)
		{
			tile->mesh.SetColor(1.0, 1.0, 1.0);
		}
		buf->mesh.SetColor(1.0, 1.0, 1.0);
		ball->ChangeBalls(buf->transform.GetTrans().x, buf->transform.GetTrans().z);
	}
	std::cout << tilenum << std::endl;
	if (ball->tilecount + 1 == tilenum)
	{
		MainState* mainstate = new MainState;
		next_state = mainstate;
		NextState();
	}
}
void GameWorld2::KeyEvent(unsigned char key)
{
	bool gotoMain = false;
	switch (key)
	{
	case 'q':
		gotoMain = true;
		break;
	case ' ':
		CheckInTile();
		break;
	}
	if (gotoMain == true)
	{
		MainState* mainstate = new MainState;
		next_state = mainstate;
		NextState();
	}

}
void GameWorld2::MouseEvent(int x, int y) {}
void GameWorld2::DataRead()
{
	FILE* dataFile;
	dataFile = fopen("ObjectData2.data", "rb");

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
