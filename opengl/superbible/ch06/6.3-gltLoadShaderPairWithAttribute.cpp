#include <GL/glut.h>

GLuint gltLoadShaderPairWithAttributes(const char *szVertexProg, const char *szFragmentProg, ...)
{
	GLuint hVertexShader;
	GLuint hFragmentShader;
	GLuint hReturn = 0;

	GLint testVal;

	hVertexShader = lgCreateShader(GL_VERTEX_SHADER);
	hFragmentShader = lgCreateShader(GL_FRAGMENT_SHADER);

	if (gltLoadShaderFile(szVertexProg, hVertexShader) == false)
	{
		glDeleteShader(hVertexShader);
		glDeleteShader(hFragmentShader);

		return (GLuint)NULL;
	}

	if (gltLoadShaderFile(szFragmentProg, hFragmentShader) == false)
	{
		glDeleteShader(hVertexShader);
		glDeleteShader(hFragmentShader);

		return (GLuint)NULL;
	}

	glCompileShader(hVertexShader);
	glCompileShader(hFragmentShader);

	glGetShaderiv(hVertexShader, GL_COMPILE_STATUS, &testVal);
	if (testVal == GL_FALSE)
	{
		char infoLog[1024];
		glGetShaderInfoLog(hVertexShader, 1024, NULL, infoLog);

		glDeleteShader(hVertexShader);
		glDeleteShader(hFragmentShader);

		return (GLuint)NULL;
	}

	glGetShaderiv(hFragmentShader, GL_COMPILE_STATUS, &testVal);
	if (testVal == GL_FALSE)
	{
		char infoLog[1024];
		glGetShaderInfoLog(hFragmentShader, 1024, NULL, infoLog);

		glDeleteShader(hVertexShader);
		glDeleteShader(hFragmentShader);

		return (GLuint)NULL;
	}

	hReturn = glCreateProgram();

	glAttachShader(hReturn, hVertexShader);
	glAttachShader(hReturn, hFragmentShader);

	va_list attributeList;

	va_start(attributeList, szFragmentProg);
	char *szNextArg;
	int iArgCount = va_arg(attributeList, int);

	for (int i = 0; i < iArgCount; ++i)
	{
		int index = va_arg(attributeList, int);
		szNextArg = va_arg(attributeList, char*);
		glBindAttribLocation(hReturn, index, szNextArg);
	}
	va_end(attributeList);
	
	glLinkProgram(hReturn);

	glDeleteShader(hVertexShader);
	glDeleteShader(hFragmentShader);

	glGetProgramiv(hReturn, GL_LINK_STATUS, &testVal);

	if (testVal == GL_FALSE)
	{
		char infoLog[1024];
		glGetProgramInfoLog(hReturn, 1024, NULL, infoLog);

		glDeleteShader(hReturn);

		return (GLuint)NULL;
	}

}
