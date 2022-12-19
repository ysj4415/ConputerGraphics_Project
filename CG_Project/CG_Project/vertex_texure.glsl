#version 330 core
layout (location = 0) in vec3 vPos; //--- ��ġ
layout (location = 1) in vec3 vNormal; //--- �븻��
layout (location = 2) in vec2 vTexCoord; //--- �ؽ�ó ��ǥ

uniform mat4 model;

out vec3 outNormal;
out vec2 TexCoord;

void main(void)
{
    gl_Position = model * vec4(vPos, 1.0f);

    outNormal = vNormal; //--- �븻�� ����
    TexCoord = vTexCoord; //--- �ؽ�ó ��ǥ ����
}