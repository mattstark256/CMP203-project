#include "Light.h"



Light::Light(GLenum _lightIndex) : lightIndex(_lightIndex)
{
}


Light::~Light()
{
}


void Light::setAmbient(float r, float g, float b, float a)
{
	ambient[0] = r;
	ambient[1] = g;
	ambient[2] = b;
	ambient[3] = a;
}


void Light::setDiffuse(float r, float g, float b, float a)
{
	diffuse[0] = r;
	diffuse[1] = g;
	diffuse[2] = b;
	diffuse[3] = a;
}


void Light::setSpecular(float r, float g, float b, float a)
{
	specular[0] = r;
	specular[1] = g;
	specular[2] = b;
	specular[3] = a;
}


void Light::setDiffuseAndSpecular(float r, float g, float b, float a)
{
	setDiffuse(r, g, b, a);
	setSpecular(r, g, b, a);
}


void Light::setAttenuation(float constant, float linear, float quadratic)
{
	attenuationConstant = constant;
	attenuationLinear = linear;
	attenuationQuadratic = quadratic;
}


void Light::setLightPosition(float x, float y, float z, float w)
{
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
	lightPosition[3] = w;
}


void Light::setSpotCutoff(float cutoff)
{
	spotCutoff = cutoff;
}


void Light::setSpotDirection(float x, float y, float z)
{
	spotDirection[0] = x;
	spotDirection[1] = y;
	spotDirection[2] = z;
}


void Light::setSpotExponent(float exponent)
{
	spotExponent = exponent;
}


void Light::render()
{
	glLightfv(lightIndex, GL_AMBIENT, ambient);
	glLightfv(lightIndex, GL_DIFFUSE, diffuse);
	glLightfv(lightIndex, GL_SPECULAR, specular);
	glLightf(lightIndex, GL_CONSTANT_ATTENUATION, attenuationConstant);
	glLightf(lightIndex, GL_LINEAR_ATTENUATION, attenuationLinear);
	glLightf(lightIndex, GL_QUADRATIC_ATTENUATION, attenuationQuadratic);

	glLightfv(lightIndex, GL_POSITION, lightPosition);

	glLightf(lightIndex, GL_SPOT_CUTOFF, spotCutoff);
	glLightfv(lightIndex, GL_SPOT_DIRECTION, spotDirection);
	glLightf(lightIndex, GL_SPOT_EXPONENT, spotExponent);

	glEnable(lightIndex);


	// For testing
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3f(0, 0, 0);
	glEnd();
}
