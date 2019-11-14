#pragma once
#include "Mesh.h"

#include <vector>
using namespace std;


class Model :
	public Mesh
{
public:
	Model(char* fileName);
	~Model();

private:
	bool loadModel(char* fileName);
};

