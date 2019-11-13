#pragma once
#include "GameObject.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Material.h"


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
};

