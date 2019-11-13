#pragma once
#include "Shape.h"


class Cuboid :
	public Shape
{
public:
	Cuboid(float sizeX = 1, float sizeY = 1, float sizeZ = 1);
	~Cuboid();
};

