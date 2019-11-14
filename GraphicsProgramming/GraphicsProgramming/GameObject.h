#pragma once
#include "Input.h"
#include "Vector3.h"
#include "glut.h"


class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void handleInput(Input* input, float dt);
	virtual void update(float dt);
	void transformAndRender();

	Vector3 getPosition();
	void setPosition(Vector3 _position);
	Vector3 getRotation();
	void setRotation(Vector3 _rotation);
	Vector3 getScale();
	void setScale(Vector3 _scale);

protected:
	Vector3 position = Vector3(0, 0, 0);
	Vector3 rotation = Vector3(0, 0, 0);
	Vector3 scale = Vector3(1, 1, 1);

	virtual void render();
};

