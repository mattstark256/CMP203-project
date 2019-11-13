#pragma once
#include "GameObject.h"
#include "Camera.h"


class Player :
	public GameObject
{
public:
	Player();
	~Player();

	void handleInput(Input* input, float dt) override;

	Camera* getCamera();

private:
	Camera* camera;

	float moveSpeed = 3;
	float rotateSpeed = 0.1;

	int frame = 0;
};

