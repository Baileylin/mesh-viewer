#version 400

in vec3 phongcolor; 

out vec4 FragColor;
void main()
{
   FragColor = vec4(phongcolor, 1.0);
}

