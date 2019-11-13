#pragma once
#include "Vector3.h"
#include "Input.h"


class Camera
{
public:
	Camera();
	~Camera();

	Vector3 getPosition();
	void setPosition(Vector3 _position);
	Vector3 getRotation();
	void setRotation(Vector3 _rotation);
	Vector3 getForward();
	Vector3 getUp();
	Vector3 getRight();
	Vector3 getLookAt();


	//void handleInput(Input* input, float dt);

private:
	Vector3 position = Vector3(0, 0, 6);
	Vector3 rotation = Vector3(0, 0, 0);

	Vector3 forward = Vector3(0, 0, 0);
	Vector3 up = Vector3(0, 0, 0);
	Vector3 right = Vector3(0, 0, 0);

	void updateVectors();
};

