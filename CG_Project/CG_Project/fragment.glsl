#version 330 core
//--- out_Color: ���ؽ� ���̴����� �Է¹޴� ���� ��
//--- FragColor: ����� ������ ������ ������ ���۷� ���� ��.

uniform vec4 vColor = vec4 (0.9, 0.8, 0.72, 1.0);
out vec4 FragColor; //--- ���� ���

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main(void)
{
FragColor = vColor;
}