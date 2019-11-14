#pragma once
#include "Mesh.h"


class Sphere :
	public Mesh
{
public:
	Sphere(int _segments = 16, int _rings = 8, float radius = 1);
	~Sphere();
};