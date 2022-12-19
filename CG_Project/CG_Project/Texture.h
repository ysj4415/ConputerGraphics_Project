#pragma once
#include "AllHeader.h"
#include "ShaderProgram.h"
#include "Transform.h"
#define _CRT_SECURE_NO_WARNINGS

class Texture
{
private:
	float vertexData[48] = {
		//--- 위치 //--- 노말 //--- 텍스처 좌표
		-0.5f, -0.5f, 0.5f, 0.0, 0.0, 1.0, 0.0, 0.0,
		0.5f, -0.5f, 0.5f, 0.0, 0.0, 1.0, 1.0, 0.0,
		0.5f, 0.5f, 0.5f, 0.0, 0.0, 1.0, 1.0, 1.0,
		0.5f, 0.5f, 0.5f, 0.0, 0.0, 1.0, 1.0, 1.0,
		-0.5f, 0.5f, 0.5f, 0.0, 0.0, 1.0, 0.0, 1.0,
		-0.5f, -0.5f, 0.5f, 0.0, 0.0, 1.0, 0.0, 0.0 };
public:
	unsigned int VBO, VAO;

	GLsizei width, height;
	unsigned int texture;
	Transform transform;
public:
	Texture();
	~Texture();
	void InitTexture(const char* c);
	void initBuffer();
	GLubyte* LoadDIBitmap(const char* filename, BITMAPINFO** info);
	void Draw();
};