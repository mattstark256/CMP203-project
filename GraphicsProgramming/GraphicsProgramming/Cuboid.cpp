#include "Cuboid.h"

#include <vector>


Cuboid::Cuboid(float sizeX, float sizeY, float sizeZ)
{
	indexCount = 24;

	verts = new float[indexCount * 3];
	norms = new float[indexCount * 3];
	texcoords = new float[indexCount * 2];

	// I'm pushing elements onto vectors cause it's a bit simpler than keeping track of array indices
	std::vector<float> vertsVector;
	std::vector<float> normsVector;
	std::vector<float> texcoordsVector;


	float halfX = sizeX / 2;
	float halfY = sizeY / 2;
	float halfZ = sizeZ / 2;


	// Front face

	vertsVector.push_back(-halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(halfZ);

	for (int i = 0; i < 4; i++)
	{
		normsVector.push_back(0);
		normsVector.push_back(0);
		normsVector.push_back(1);
	}


	// Back face

	vertsVector.push_back(halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(-halfZ);

	for (int i = 0; i < 4; i++)
	{
		normsVector.push_back(0);
		normsVector.push_back(0);
		normsVector.push_back(-1);
	}


	// Left face

	vertsVector.push_back(-halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(halfZ);

	for (int i = 0; i < 4; i++)
	{
		normsVector.push_back(-1);
		normsVector.push_back(0);
		normsVector.push_back(0);
	}


	// Right face

	vertsVector.push_back(halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(-halfZ);

	for (int i = 0; i < 4; i++)
	{
		normsVector.push_back(1);
		normsVector.push_back(0);
		normsVector.push_back(0);
	}


	// Bottom face

	vertsVector.push_back(halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(-halfY);
	vertsVector.push_back(-halfZ);

	for (int i = 0; i < 4; i++)
	{
		normsVector.push_back(0);
		normsVector.push_back(-1);
		normsVector.push_back(0);
	}


	// Top face

	vertsVector.push_back(-halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(-halfZ);

	vertsVector.push_back(-halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(halfZ);

	vertsVector.push_back(halfX);
	vertsVector.push_back(halfY);
	vertsVector.push_back(-halfZ);

	for (int i = 0; i < 4; i++)
	{
		normsVector.push_back(0);
		normsVector.push_back(1);
		normsVector.push_back(0);
	}


	// Texture coordinates

	for (int i = 0; i < 6; i++)
	{
		texcoordsVector.push_back(0);
		texcoordsVector.push_back(0);

		texcoordsVector.push_back(0);
		texcoordsVector.push_back(1);

		texcoordsVector.push_back(1);
		texcoordsVector.push_back(1);

		texcoordsVector.push_back(1);
		texcoordsVector.push_back(0);
	}


	for (int i = 0; i < vertsVector.size(); i++)
	{
		verts[i] = vertsVector[i];
	}

	for (int i = 0; i < normsVector.size(); i++)
	{
		norms[i] = normsVector[i];
	}

	for (int i = 0; i < texcoordsVector.size(); i++)
	{
		texcoords[i] = texcoordsVector[i];
	}
}


Cuboid::~Cuboid()
{
}
