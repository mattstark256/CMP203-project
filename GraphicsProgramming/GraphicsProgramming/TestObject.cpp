#include "TestObject.h"



TestObject::TestObject()
{
	sphere = new Sphere(64, 32, 0.5);
	sphere->setPosition(Vector3(0, 1, 0));

	cuboid = new Cuboid(2, 0.5, 1);

	mat1 = new Material();
	mat1->setTexture("gfx/cratearrow.png");

	mat2 = new Material();
	mat2->setAmbientAndDiffuse(1, 0, 0, 1);
	mat2->setSpecular(1, 1, 1, 1);
}


TestObject::~TestObject()
{
}


void TestObject::update(float dt)
{
	rotation = Vector3(rotation.x, rotation.y + dt * 90, rotation.z);

	cuboid->setRotation(Vector3(cuboid->getRotation().x, cuboid->getRotation().y, cuboid->getRotation().z + dt * 90));
}


void TestObject::render()
{
	mat1->apply();
	cuboid->transformAndRender();

	mat2->apply();
	sphere->transformAndRender();

	//glBegin(GL_TRIANGLES);
	//glVertex3f(-1, 0, 0);
	//glVertex3f(0, 1, 0);
	//glVertex3f(1, 0, 0);
	//glEnd();
}
