#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}


void GameObject::handleInput(Input* input, float dt)
{
}


void GameObject::update(float dt)
{
}


void GameObject::transformAndRender()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.z, 0, 0, 1);

	render();

	glPopMatrix();
}


Vector3 GameObject::getPosition()
{
	return position;
}


void GameObject::setPosition(Vector3 _position)
{
	position = _position;
}


Vector3 GameObject::getRotation()
{
	return rotation;
}


void GameObject::setRotation(Vector3 _rotation)
{
	rotation = _rotation;
}


void GameObject::render()
{
}
