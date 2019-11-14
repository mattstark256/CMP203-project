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
	glScalef(scale.x, scale.y, scale.z);

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


Vector3 GameObject::getScale()
{
	return scale;
}


void GameObject::setScale(Vector3 _scale)
{
	scale = _scale;
}


void GameObject::setScale(float _scale)
{
	scale.x = _scale;
	scale.y = _scale;
	scale.z = _scale;
}


void GameObject::render()
{
}

