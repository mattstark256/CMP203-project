#include "Material.h"
#include "SOIL.h"



Material::Material()
{
}


Material::~Material()
{
}


void Material::apply()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glBindTexture(GL_TEXTURE_2D, texture);
}


void Material::setAmbient(float r, float g, float b, float a)
{
	ambient[0] = r;
	ambient[1] = g;
	ambient[2] = b;
	ambient[3] = a;
}


void Material::setDiffuse(float r, float g, float b, float a)
{
	diffuse[0] = r;
	diffuse[1] = g;
	diffuse[2] = b;
	diffuse[3] = a;
}


void Material::setAmbientAndDiffuse(float r, float g, float b, float a)
{
	setAmbient(r, g, b, a);
	setDiffuse(r, g, b, a);
}


void Material::setSpecular(float r, float g, float b, float a)
{
	specular[0] = r;
	specular[1] = g;
	specular[2] = b;
	specular[3] = a;
}


void Material::setShininess(float s)
{
	shininess[0] = s;
}


void Material::setTexture(const char* filePath)
{
	texture = SOIL_load_OGL_texture
	(
		filePath,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}
