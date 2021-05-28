#version 400

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNormal;

out vec3 color;
uniform mat4 mvp;
uniform float time;

void main()
{  
   vec3 pos = vPos + 0.05 * vNormal * sin(10*time+vPos.x*100.0);
   color = 0.5 * (vNormal + vec3(1.0));
   gl_Position = mvp * vec4(vPos, 1.0);
}
