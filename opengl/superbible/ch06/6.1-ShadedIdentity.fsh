#version 330

out vec4 vFragColor;
int vec4 vVaryingColor;

void main(void)
{
	vFragColor = vVaryingColor;
}
