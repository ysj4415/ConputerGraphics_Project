#pragma once

#include "AllHeader.h"

class Light
{
public:
	unsigned int lightPosLocation;
	unsigned int lightColorLocation;
	unsigned int viewPosLocation;

public:
	Light();
	~Light();

	void Setting();
};