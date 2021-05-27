#version 400

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNor;

struct LightInfo
{
	vec3 position;
	vec3 color;
};

struct Material
{
	vec3 Kd;
	vec3 Ka;
	vec3 Ks;
	float shininess;
};

uniform LightInfo uLight;
uniform Material uMaterial;
uniform mat4 uMV;
uniform mat4 mvp;
uniform mat3 uNMV;

out vec3 phongcolor;



void main()
{
	vec4 vertex_eye = uMV * vec4(vPos, 1.0);
	vec3 normal_eye = normalize(uNMV * vNor);
	vec3 s = normalize(uLight.position.xyz - vec3(vertex_eye));
	float angle = max(dot(s, normal_eye), 0.0);
	vec3 diffuse = angle * uLight.color * uMaterial.Kd;
	vec3 ambient = uMaterial.Ka * uLight.color;
	vec3 r = normalize(reflect(-s, normal_eye));
	vec3 v = normalize(-vertex_eye.xyz);
	vec3 specular = uMaterial.Ks * uLight.color * pow( max(0.0, dot(r,v) ) , uMaterial.shininess);
	phongcolor = ambient + diffuse + specular;
	gl_Position = mvp * vec4(vPos, 1.0);
}


