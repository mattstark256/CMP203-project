#pragma once
#include "Mesh.h"


class Cuboid :
	public Mesh
{
public:
	Cuboid(float sizeX = 1, float sizeY = 1, float sizeZ = 1);
	~Cuboid();
};

