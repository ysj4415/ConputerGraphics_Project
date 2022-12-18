#version 330 core
layout (location = 0) in vec3 in_Position; //--- 위치 변수: attribute position 0
//layout (location = 0) in vec4 in_Position; //--- 위치 변수: attribute position 0

layout(location = 1) in vec3 in_Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 FragPos;
out vec3 Normal;

void main(void)
{
    gl_Position = projection * view * model * vec4(in_Position, 1.0f);

    FragPos = vec3(model * vec4(in_Position, 1.0));

    Normal = in_Normal;
}