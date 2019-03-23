#pragma once

#include "ObjectHandlerVertex.h"
#include "ObjectHandlerElement.h"

#include "Shader.h"


class ProgramRenderer
{
public:
	ProgramRenderer(const char* pathVertex, const char* pathFragment);

	~ProgramRenderer();


	ObjectHandlerVertex* addObjectHandler(const char* arrayPath);
	ObjectHandlerElement* addObjectHandler(const char* arrayPath, const char* elementPath);



	void draw();

private:

	void createUniforms();



	Shader program;


	std::vector<ObjectHandler*> objectHandlerArray;

};

