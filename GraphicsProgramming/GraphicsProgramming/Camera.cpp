#include "Camera.h"
#include "glut.h"

#define DEG_TO_RAD 0.017453 // Used to convert degrees to radians. Equal to pi / 180.


Camera::Camera()
{
	updateVectors();
}


Camera::~Camera()
{
}


Vector3 Camera::getPosition()
{
	return position;
}


void Camera::setPosition(Vector3 _position)
{
	position = _position;
}

Vector3 Camera::getRotation()
{
	return rotation;
}


void Camera::setRotation(Vector3 _rotation)
{
	rotation = _rotation;
	updateVectors();
}


Vector3 Camera::getForward()
{
	return forward;
}


Vector3 Camera::getUp()
{
	return up;
}

Vector3 Camera::getRight()
{
	return right;
}


Vector3 Camera::getLookAt()
{
	return position + forward;
}


// Calculate the forward, up and right vectors
void Camera::updateVectors()
{
	float cosY = cosf(rotation.y * DEG_TO_RAD);
	float cosP = cosf(rotation.x * DEG_TO_RAD);
	float cosR = cosf(rotation.z * DEG_TO_RAD);
	float sinY = sinf(rotation.y * DEG_TO_RAD);
	float sinP = sinf(rotation.x * DEG_TO_RAD);
	float sinR = sinf(rotation.z * DEG_TO_RAD);

	forward.x = sinY * cosP;
	forward.y = sinP;
	forward.z = cosP * -cosY;

	up.x = -cosY * sinR - sinY * sinP * cosR;
	up.y = cosP * cosR;
	up.z = -sinY * sinR - sinP * cosR * -cosY;

	right = forward.cross(up);
}
