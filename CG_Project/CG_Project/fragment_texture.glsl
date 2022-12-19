#version 330 core
out vec4 FragColor; //--- 색상 출력

in vec3 outNormal;
in vec2 TexCoord;

uniform sampler2D outTexture;  //--- 텍스처 샘플러

void main(void)
{
	FragColor = texture (outTexture, TexCoord);
}