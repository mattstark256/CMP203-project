// Below ifdef required to remove warnings for unsafe version of fopen and fscanf.
// Secure version won't work cross-platform, forcing this small hack.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "Model.h"

#include <iostream>


Model::Model(char* fileName)
{
	bool result = loadModel(fileName);
	if (!result)
	{
		MessageBox(NULL, "Model failed to load", "Error", MB_OK);
	}
}


Model::~Model()
{
}


bool Model::loadModel(char* fileName)
{
	vector<Vector3> vertsVector;
	vector<Vector3> normsVector;
	vector<Vector3> texcoordsVector;
	vector<unsigned int> faces;

	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		MessageBox(NULL, "file is null", "Error", MB_OK);
		return false;
	}
	while (true)
	{
		char lineHeader[128];

		// Read first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
		{
			break; // exit loop
		}
		else // Parse
		{
			if (strcmp(lineHeader, "v") == 0) // Vertex
			{
				Vector3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				vertsVector.push_back(vertex);
			}
			else if (strcmp(lineHeader, "vt") == 0) // Tex Coord
			{
				Vector3 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				texcoordsVector.push_back(uv);
			}
			else if (strcmp(lineHeader, "vn") == 0) // Normal
			{
				Vector3 normal;
				fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
				normsVector.push_back(normal);
			}
			else if (strcmp(lineHeader, "f") == 0) // Face
			{
				unsigned int face[9];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &face[0], &face[1], &face[2],
					&face[3], &face[4], &face[5],
					&face[6], &face[7], &face[8]);
				if (matches != 9)
				{
					// Parser error, or not triangle faces
					return false;
				}

				for (int i = 0; i < 9; i++)
				{
					faces.push_back(face[i]);
				}


			}
		}
	}

	indexCount = faces.size() / 3;
	verts = new float[indexCount * 3];
	norms = new float[indexCount * 3];
	texcoords = new float[indexCount * 2];
	for (int i = 0; i < indexCount; i++)
	{
		Vector3 vert = vertsVector[faces[i * 3] - 1];
		verts[i * 3] = vert.x;
		verts[i * 3 + 1] = vert.y;
		verts[i * 3 + 2] = vert.z;

		Vector3 texCoord = texcoordsVector[faces[i * 3 + 1] - 1];
		texcoords[i * 2] = texCoord.x;
		texcoords[i * 2 + 1] = texCoord.y;

		Vector3 normal = normsVector[faces[i * 3 + 2] - 1];
		norms[i * 3] = normal.x;
		norms[i * 3 + 1] = normal.y;
		norms[i * 3 + 2] = normal.z;
	}


	// Once data has been sorted clear read data (which has been copied and are not longer needed).
	vertsVector.clear();
	texcoordsVector.clear();
	normsVector.clear();
	faces.clear();

	return true;
}
