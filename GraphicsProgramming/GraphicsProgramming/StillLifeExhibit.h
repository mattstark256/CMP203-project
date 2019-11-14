#pragma once
#include "GameObject.h"

#include "Material.h"
#include "Model.h"


class StillLifeExhibit :
	public GameObject
{
public:
	StillLifeExhibit();
	~StillLifeExhibit();

	void update(float dt) override;

protected:
	void render() override;


private:
	Model* table;
	Material* matTable;

	Model* flowerVase;
	Model* flowerStem;
	Model* flowerPetals;
	Model* flowerCentre;

	Material* matFlowerVase;
	Material* matFlowerStem;
	Material* matFlowerPetals;
	Material* matFlowerCentre;

};

