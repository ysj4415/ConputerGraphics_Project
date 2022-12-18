#version 330 core
//--- out_Color: 버텍스 세이더에서 입력받는 색상 값
//--- FragColor: 출력할 색상의 값으로 프레임 버퍼로 전달 됨.

uniform vec3 vColor;
out vec4 FragColor; //--- 색상 출력

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

in vec3 FragPos;
in vec3 Normal;

void main(void)
{
	// 주변 조명
	float ambientLight = 0.3;
	vec3 ambient = ambientLight * lightColor;

	// 산란 반사 조명
	vec3 normalVector = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diffuseLight = max(dot(normalVector, lightDir), 0.0);
	vec3 diffuse = diffuseLight * lightColor;

	// 거울 반사 조명
	float spec_strength = 1.0;
	int shininess = 128;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, normalVector);
	float specularLight = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = spec_strength * specularLight * lightColor;
	
	vec3 result = (ambient + diffuse + specular) * vColor;

	FragColor = vec4(result, 1.0);
}