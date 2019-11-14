#include "TestObject.h"



TestObject::TestObject()
{
	sphere = new Sphere(64, 32, 0.5);
	sphere->setPosition(Vector3(0, 1, -1));

	cuboid = new Cuboid(2, 0.5, 1);
	cuboid->setPosition(Vector3(0, -1, -1));

	mat1 = new Material();
	mat1->setTexture("gfx/cratearrow.png");

	mat2 = new Material();
	mat2->setAmbientAndDiffuse(1, 0, 0, 1);
	mat2->setSpecular(1, 1, 1, 1);

	// Set up flower models
	flowerVase = new Model("models/Blender/FlowerVase.obj");
	flowerStem = new Model("models/Blender/FlowerStem.obj");
	flowerPetals = new Model("models/Blender/FlowerPetals.obj");
	flowerCentre = new Model("models/Blender/FlowerCentre.obj");
	flowerVase->setScale(Vector3(0.5, 0.5, 0.5));
	flowerStem->setScale(Vector3(0.5, 0.5, 0.5));
	flowerPetals->setScale(Vector3(0.5, 0.5, 0.5));
	flowerCentre->setScale(Vector3(0.5, 0.5, 0.5));

	// Set up flower materials
	matFlowerVase = new Material();
	matFlowerVase->setAmbientAndDiffuse(0.5, 0.5, 1, 1);
	matFlowerVase->setSpecular(1, 1, 1, 1);
	matFlowerVase->setShininess(30);
	matFlowerStem = new Material();
	matFlowerStem->setAmbientAndDiffuse(0.1, 0.8, 0.4, 1);
	matFlowerVase->setSpecular(0.7, 0.7, 0.7, 1);
	matFlowerPetals = new Material();
	matFlowerPetals->setAmbientAndDiffuse(1, 0.6, 0.9, 1);
	matFlowerCentre = new Material();
	matFlowerCentre->setAmbientAndDiffuse(1, 1, 0.3, 1);
}


TestObject::~TestObject()
{
}


void TestObject::update(float dt)
{
	//rotation = Vector3(rotation.x, rotation.y + dt * 90, rotation.z);

	cuboid->setRotation(Vector3(cuboid->getRotation().x, cuboid->getRotation().y, cuboid->getRotation().z + dt * 90));
}


void TestObject::render()
{
	mat1->apply();
	cuboid->transformAndRender();

	mat2->apply();
	sphere->transformAndRender();
	flowerStem->transformAndRender();

	// Render flower
	matFlowerVase->apply();
	flowerVase->transformAndRender();
	matFlowerStem->apply();
	flowerStem->transformAndRender();
	matFlowerPetals->apply();
	flowerPetals->transformAndRender();
	matFlowerCentre->apply();
	flowerCentre->transformAndRender();
}
