#version 330 core
layout (location = 0) in vec3 vPos; //--- 위치
layout (location = 1) in vec3 vNormal; //--- 노말값
layout (location = 2) in vec2 vTexCoord; //--- 텍스처 좌표

uniform mat4 model;

out vec3 outNormal;
out vec2 TexCoord;

void main(void)
{
    gl_Position = model * vec4(vPos, 1.0f);

    outNormal = vNormal; //--- 노말값 전달
    TexCoord = vTexCoord; //--- 텍스처 좌표 전달
}