#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "AllHeader.h"
#include "Mesh.h"

class Ball : public Actor
{
private:
	int starttimer = 0;
	int endtimer = 0;
	GLfloat speed;
	GLfloat life;
public:
	Mesh main_ball;
	Mesh sub_ball;
	Line main_ball_guideline;
	Line sub_ball_guideline;

	int tilecount;
public:
	Ball();
	~Ball();
	void Draw(glm::mat4 view, glm::mat4 projection);
	glm::vec4 GetSubBallLoc();
	void ChangeBalls(GLfloat x, GLfloat z);
	void InitBuffer();

	void Update();
};

