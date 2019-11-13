#pragma once
#include "GameObject.h"


class Light :
	public GameObject
{
public:
	Light(GLenum _lightIndex);
	~Light();

	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void setDiffuseAndSpecular(float r, float g, float b, float a);
	void setAttenuation(float constant, float linear, float quadratic);

	void setLightPosition(float x, float y, float z, float w);

	void setSpotCutoff(float cutoff);
	void setSpotDirection(float x, float y, float z);
	void setSpotExponent(float exponent);

protected:
	void render() override;

private:
	GLenum lightIndex;
	GLfloat ambient[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat attenuationConstant = 1;
	GLfloat attenuationLinear = 0;
	GLfloat attenuationQuadratic = 0;

	// This is only modified for directional lights
	GLfloat lightPosition[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	// These are only modified for spot lights
	GLfloat spotCutoff = 180;
	GLfloat spotDirection[3] = { 0.0f, -1.0f, 0.0f };
	GLfloat spotExponent = 1;

};

