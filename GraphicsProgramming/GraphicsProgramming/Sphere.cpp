#include "Sphere.h"
#include <cmath>

#define PI 3.14159265


Sphere::Sphere(int segments, int rings, float radius)
{
	int vertexCount = (segments + 1) * (rings + 1);
	verts = new float[vertexCount * 3];
	norms = new float[vertexCount * 3];
	texcoords = new float[vertexCount * 2];
	indexCount = segments * rings * 4;
	useIndexArray = true;
	indices = new GLushort[indexCount];

	// Generate the verts, norms and texcoords
	for (int ring = 0; ring < rings + 1; ring++)
	{
		float latitude = ((float)ring / rings) * PI;

		for (int segment = 0; segment < segments + 1; segment++)
		{
			float longitude = ((float)segment / segments) * PI * 2;

			float x = sin(latitude) * cos(longitude);
			float y = cos(latitude);
			float z = sin(latitude) * sin(longitude);

			int index = ring * (segments + 1) + segment;

			verts[index * 3] = x * radius;
			verts[index * 3 + 1] = y * radius;
			verts[index * 3 + 2] = z * radius;

			norms[index * 3] = x;
			norms[index * 3 + 1] = y;
			norms[index * 3 + 2] = z;

			texcoords[index * 2] = (float)segment / segments;
			texcoords[index * 2 + 1] = (float)ring / rings;
		}
	}

	// Generate the indices
	for (int ring = 0; ring < rings; ring++)
	{
		for (int segment = 0; segment < segments; segment++)
		{
			int index = ring * segments + segment;
			int firstVertex = ring * (segments + 1) + segment;
			indices[index * 4] = firstVertex;
			indices[index * 4 + 1] = firstVertex + segments + 1;
			indices[index * 4 + 2] = firstVertex + segments + 1 + 1;
			indices[index * 4 + 3] = firstVertex + 1;
		}
	}
}


Sphere::~Sphere()
{
}
