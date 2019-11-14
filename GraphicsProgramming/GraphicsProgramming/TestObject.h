#pragma once
#include "GameObject.h"

#include "Material.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Model.h"


class TestObject :
	public GameObject
{
public:
	TestObject();
	~TestObject();

	void update(float dt) override;

protected:
	void render() override;

private:
	Sphere* sphere;
	Cuboid* cuboid;

	Material* mat1;
	Material* mat2;

	Model* flowerVase;
	Model* flowerStem;
	Model* flowerPetals;
	Model* flowerCentre;

	Material* matFlowerVase;
	Material* matFlowerStem;
	Material* matFlowerPetals;
	Material* matFlowerCentre;
};

