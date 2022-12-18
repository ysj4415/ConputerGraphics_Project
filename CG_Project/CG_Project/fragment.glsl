#version 330 core
//--- out_Color: ���ؽ� ���̴����� �Է¹޴� ���� ��
//--- FragColor: ����� ������ ������ ������ ���۷� ���� ��.

uniform vec3 vColor;
out vec4 FragColor; //--- ���� ���

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

in vec3 FragPos;
in vec3 Normal;

void main(void)
{
	// �ֺ� ����
	float ambientLight = 0.3;
	vec3 ambient = ambientLight * lightColor;

	// ��� �ݻ� ����
	vec3 normalVector = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diffuseLight = max(dot(normalVector, lightDir), 0.0);
	vec3 diffuse = diffuseLight * lightColor;

	// �ſ� �ݻ� ����
	float spec_strength = 1.0;
	int shininess = 128;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, normalVector);
	float specularLight = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = spec_strength * specularLight * lightColor;
	
	vec3 result = (ambient + diffuse + specular) * vColor;

	FragColor = vec4(result, 1.0);
}