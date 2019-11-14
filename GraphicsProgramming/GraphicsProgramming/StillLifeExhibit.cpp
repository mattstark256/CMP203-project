#include "StillLifeExhibit.h"



StillLifeExhibit::StillLifeExhibit()
{
	// Set up table
	table = new Model("models/Blender/Table.obj");
	matTable = new Material();

	// Set up flower models
	flowerVase = new Model("models/Blender/FlowerVase.obj");
	flowerStem = new Model("models/Blender/FlowerStem.obj");
	flowerPetals = new Model("models/Blender/FlowerPetals.obj");
	flowerCentre = new Model("models/Blender/FlowerCentre.obj");
	float flowerScale = 0.35;
	flowerVase->setScale(flowerScale);
	flowerStem->setScale(flowerScale);
	flowerPetals->setScale(flowerScale);
	flowerCentre->setScale(flowerScale);

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


StillLifeExhibit::~StillLifeExhibit()
{
}


void StillLifeExhibit::update(float dt)
{
}


void StillLifeExhibit::render()
{
	// Render table
	matTable->apply();
	table->transformAndRender();

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
