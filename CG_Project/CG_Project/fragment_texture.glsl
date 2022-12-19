#version 330 core
out vec4 FragColor; //--- ���� ���

in vec3 outNormal;
in vec2 TexCoord;

uniform sampler2D outTexture;  //--- �ؽ�ó ���÷�

void main(void)
{
	FragColor = texture (outTexture, TexCoord);
}