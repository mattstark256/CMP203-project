#pragma once
#include "GameObject.h"


class Mesh :
	public GameObject
{
protected:
	float* verts;
	float* norms;
	float* texcoords;
	int indexCount;
	bool useIndexArray = false;
	GLuint* indices;
	GLenum faceMode = GL_TRIANGLES;

	void render() override;
};