#pragma once

#include "glut.h"
#include <string>


class Material
{
public:
	Material();
	~Material();

	void apply();

	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setAmbientAndDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void setShininess(float s);
	void setTexture(const char* fileName);

private:
	GLfloat ambient[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat diffuse[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[4] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat shininess[1] = { 10.0 };
	GLuint texture = 0;
};

