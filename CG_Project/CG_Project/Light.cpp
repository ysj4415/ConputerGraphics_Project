#pragma once

#include "Light.h"
#include "ShaderProgram.h"

Light::Light()
{
	lightPosLocation = 0;
	lightColorLocation = 0;
	viewPosLocation = 0;
}

Light::~Light()
{
}


void Light::Setting()
{
	glUseProgram(s_program);

	lightPosLocation = glGetUniformLocation(s_program, "lightPos");
	glUniform3f(lightPosLocation, 0.0f, 20.0f, 0.0f);
	lightColorLocation = glGetUniformLocation(s_program, "lightColor");
	glUniform3f(lightColorLocation, 1.0, 1.0, 1.0);
	viewPosLocation = glGetUniformLocation(s_program, "viewPos");
	glUniform3f(viewPosLocation, 0.0f, 20.0f, 0.0f);
}