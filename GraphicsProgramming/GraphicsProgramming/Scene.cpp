#include "Scene.h"

#include "Camera.h"
#include "TestObject.h"
#include "Light.h"


// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input* in)
{
	// Store pointer for input class
	input = in;

	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	// Other OpenGL / render setting should be applied here.
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_CULL_FACE); // Don't draw backfaces
	glEnable(GL_NORMALIZE); // Fix normals on scaled objects


	// Initialise scene variables
	player = new Player();
	player->setPosition(Vector3(0, 0, 6));
	gameObjects.push_back(player);

	TestObject* testObject = new TestObject();
	testObject->setPosition(Vector3(1, 0, 0));
	testObject->setRotation(Vector3(0, -90, 0));
	gameObjects.push_back(testObject);

	testObject = new TestObject();
	testObject->setPosition(Vector3(-1, 0, 0));
	testObject->setRotation(Vector3(0, 30, 20));
	gameObjects.push_back(testObject);

	Light* light = new Light(GL_LIGHT0);
	light->setPosition(Vector3(0, 2, 2));
	light->setAttenuation(1, 0.3, 0);
	gameObjects.push_back(light);
}


void Scene::handleInput(float dt)
{
	// Handle user input
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->handleInput(input, dt);
	}
}


void Scene::update(float dt)
{
	// update scene related variables.
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->update(dt);
	}

	// Calculate FPS for output
	calculateFPS();
}


void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera

	Camera* cam = player->getCamera();
	gluLookAt(
		cam->getPosition().getX(),
		cam->getPosition().getY(),
		cam->getPosition().getZ(),
		cam->getLookAt().getX(),
		cam->getLookAt().getY(),
		cam->getLookAt().getZ(),
		cam->getUp().getX(),
		cam->getUp().getY(),
		cam->getUp().getZ());

	// Render geometry/scene here -------------------------------------

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->transformAndRender();
	}

	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();

	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}


// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h)
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);


}


// Calculates FPS
void Scene::calculateFPS()
{

	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame * 1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}


// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}


// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width / (float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}
