#pragma once
#include "Shape.h"


class Sphere :
	public Shape
{
public:
	Sphere(int _segments = 16, int _rings = 8, float radius = 1);
	~Sphere();
};