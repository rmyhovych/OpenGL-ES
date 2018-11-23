#pragma once

#include "window.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Object
{
public:
	Object(glm::vec3 position, glm::vec3 scale, glm::vec3 color);

	void move(glm::vec3 vector);
	void rotate(glm::vec3 axis, float angle);
	void scale(glm::vec3 vector);
	void setColor(glm::vec3 color);

	void linkRotation(const char* name, GLuint ID);
	void linkModel(const char* name, GLuint ID);
	void linkColor(const char* name, GLuint ID);

	void use();

private:
	void constructModel();

protected:

	// Object properties
	glm::vec3 position_;
	glm::vec3 scale_;
	
	glm::mat4 rotation_;
	glm::mat4 model_;

	glm::vec3 color_;

	bool modified_;

	// Shader uniforms
	GLuint rotationPtr_;
	GLuint modelPtr_;
	GLuint colorPtr_;
};

