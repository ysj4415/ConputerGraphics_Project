#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include "Tile.h"

Tile* ReadData(const char* datafile)
{
	FILE* dataFile;
	dataFile = fopen(datafile, "rb");

	int tilenum = 0;

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
			fscanf(objFile, "%f %f %f",
				&vertex[vertIndex].x, &vertex[vertIndex].y,
				&vertex[vertIndex].z);
			vertIndex++;
		}
		else if (count[0] == 'vn' && count[1] == '\0') {
			fscanf(objFile, "%f %f %f",
				&vertex_nomal[vertNIndex].x, &vertex_nomal[vertNIndex].y,
				&vertex_nomal[vertNIndex].z);
			vertNIndex++;
		}
		else if (count[0] == 'vt' && count[1] == '\0') {
			fscanf(objFile, "%f %f %f",
				&vertex_texture[vertTIndex].x, &vertex_texture[vertTIndex].y,
				&vertex_texture[vertTIndex].z);
			vertTIndex++;
		}
		else if (count[0] == 'f' && count[1] == '\0') {
			fscanf(objFile, "%d/%d/%d %d/%d/%d %d/%d/%d",
				&face_v[faceIndex * 3], &face_vt[faceIndex * 3], &face_vn[faceIndex * 3],
				&face_v[faceIndex * 3 + 1], &face_vt[faceIndex * 3 + 1], &face_vn[faceIndex * 3 + 1],
				&face_v[faceIndex * 3 + 2], &face_vt[faceIndex * 3 + 2], &face_vn[faceIndex * 3 + 2]);

			face_v[faceIndex * 3]--; face_v[faceIndex * 3 + 1]--; face_v[faceIndex * 3 + 2]--;
			face_vt[faceIndex * 3]--; face_vt[faceIndex * 3 + 1]--; face_vt[faceIndex * 3 + 2]--;
			face_vn[faceIndex * 3]--; face_vn[faceIndex * 3 + 1]--; face_vn[faceIndex * 3 + 2]--;
			faceIndex++;
		}
	}

	fclose(objFile);
}