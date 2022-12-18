#version 330 core
//--- out_Color: 버텍스 세이더에서 입력받는 색상 값
//--- FragColor: 출력할 색상의 값으로 프레임 버퍼로 전달 됨.

uniform vec4 vColor = vec4 (0.9, 0.8, 0.72, 1.0);
out vec4 FragColor; //--- 색상 출력

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main(void)
{
FragColor = vColor;
}