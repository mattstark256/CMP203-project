#include "Player.h"
#include "glut.h"



Player::Player()
{
	// Hide the cursor
	glutSetCursor(GLUT_CURSOR_NONE);

	camera = new Camera();
}


Player::~Player()
{
}


void Player::handleInput(Input* input, float dt)
{
	// Get the centre of the window
	int windowCentreX = glutGet(GLUT_WINDOW_WIDTH) / 2;
	int windowCentreY = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	// Get the position of the mouse relative to the centre of the window
	float yawAmount = input->getMouseX() - windowCentreX;
	float pitchAmount = -(input->getMouseY() - windowCentreY);
	// Move the mouse back to the centre of the window
	glutWarpPointer(windowCentreX, windowCentreY);

	// For the first two frames don't do anything because the mouse position hasn't been reset
	frame++;
	if (frame > 2) camera->setRotation(camera->getRotation() + Vector3(pitchAmount * rotateSpeed, yawAmount * rotateSpeed, 0));

	// Create a vector representing the movement input
	Vector3 inputVector(0, 0, 0);
	if (input->isKeyDown('s')) inputVector.z -= 1;
	if (input->isKeyDown('w')) inputVector.z += 1;
	if (input->isKeyDown('a')) inputVector.x -= 1;
	if (input->isKeyDown('d')) inputVector.x += 1;
	if (input->isKeyDown('q')) inputVector.y -= 1;
	if (input->isKeyDown('e')) inputVector.y += 1;

	// Create a vector representing the distance to move
	inputVector.normalise();
	Vector3 right = camera->getRight();
	Vector3 up = camera->getUp();
	Vector3 forward = camera->getForward();
	Vector3 moveVector(
		inputVector.x * right.x + inputVector.y * up.x + inputVector.z * forward.x,
		inputVector.x * right.y + inputVector.y * up.y + inputVector.z * forward.y,
		inputVector.x * right.z + inputVector.y * up.z + inputVector.z * forward.z);
	moveVector.scale(dt);
	moveVector.scale(moveSpeed);

	// Move the player and the camera
	position += moveVector;
	camera->setPosition(position);
}


Camera * Player::getCamera()
{
	return camera;
}
