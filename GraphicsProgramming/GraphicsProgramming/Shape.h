#ifndef _SHAPE_H
#define _SHAPE_H

#include "GameObject.h"


class Shape :
	public GameObject
{
protected:
	float* verts;
	float* norms;
	float* texcoords;
	int indexCount;
	bool useIndexArray = false;
	GLushort* indices;

	void render() override;
};
#endif