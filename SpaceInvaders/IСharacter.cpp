#include "stdafx.h"
#include "IÑharacter.h"


void IÑharacter::setFile(const String &strFile)
{
	_nameFileSprite = strFile;
}

const String IÑharacter::getFile() const
{
	return _nameFileSprite;
}

void IÑharacter::imageLoadFromFile(const String &strFile)
{
	_image.loadFromFile(strFile);
}

Image IÑharacter::getImage() const
{
	return _image;
};

Texture & IÑharacter::getTexture()
{
	return _texture;
}

void IÑharacter::setX(float x)
{
	_x = x;
}

float IÑharacter::getX() const
{
	return _x;
}

void IÑharacter::setY(float y)
{
	_y = y;
}

float IÑharacter::getY() const
{
	return _y;
}

void IÑharacter::setDX(float dx)
{
	_dx = dx;
}

float IÑharacter::getDX() const
{
	return _dx;
}

void IÑharacter::setDY(float dy)
{
	_dy = dy;
}

float IÑharacter::getDY() const
{
	return _dy;
}

void IÑharacter::setSpeed(float speed)
{
	_speed = speed;
}

float IÑharacter::getSpeed() const
{
	return _speed;
}

void IÑharacter::setWidth(unsigned int  width)
{
	_width = width;
}

unsigned int  IÑharacter::getWidth() const
{
	return _width;
}

void IÑharacter::setHeight(unsigned int  height)
{
	_height = height;
}

unsigned int  IÑharacter::getHeight() const
{
	return _height;
}

void IÑharacter::setLife(bool life)
{
	_life = life;
}

bool IÑharacter::getLife() const
{
	return _life;
}

void IÑharacter::setTextureRect(float x, float y, float width, float height)
{
	getSprite().setTextureRect(IntRect((int)x, (int)y, (int)width, (int)height));
}