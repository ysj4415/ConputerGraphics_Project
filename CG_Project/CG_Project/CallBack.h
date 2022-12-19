#pragma once
#include "AllHeader.h"

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
GLvoid TimerFunction(int value);
GLvoid SpecialKeyboard(int key, int x, int y);
void Mouse(int button, int state, int x, int y);