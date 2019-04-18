#pragma once

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#ifdef ANDROID_ES
#include <GLES3/gl3.h>
#else
#define GLEW_STATIC	
#include <GL/glew.h>
#endif

#include "FileData.h"



class Shader
{


	//=============================================================================================
	//  STATIC
	//=============================================================================================

public:

	static void addVertexBuffer(FileData& vertexBuffer);
	static GLuint addElementBuffer(FileData& elementBuffer);

	static void linkLayout(int index, int size, int attributeSize, int offset);



	static GLuint createProgram(FileData& vertexShaderCode, FileData& fragmentShaderCode);


private:

	static GLuint compileShader(GLuint type, FileData& shaderCode);






	//=============================================================================================
	//  OBJECT
	//=============================================================================================

public:

	Shader(const char* vertexCodePath, const char* fragmentCodePath);


	int getUniformLocation(const char* name);

	void use();

private:

	GLuint id;

};