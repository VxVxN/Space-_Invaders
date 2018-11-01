#include "stdafx.h"
#include "I�haracter.h"


void I�haracter::setFile(const String &strFile)
{
	_nameFileSprite = strFile;
}

const String I�haracter::getFile() const
{
	return _nameFileSprite;
}

void I�haracter::imageLoadFromFile(const String &strFile)
{
	_image.loadFromFile(strFile);
}

Image I�haracter::getImage() const
{
	return _image;
};

Texture & I�haracter::getTexture()
{
	return _texture;
}

void I�haracter::setX(float x)
{
	_x = x;
}

float I�haracter::getX() const
{
	return _x;
}

void I�haracter::setY(float y)
{
	_y = y;
}

float I�haracter::getY() const
{
	return _y;
}

void I�haracter::setDX(float dx)
{
	_dx = dx;
}

float I�haracter::getDX() const
{
	return _dx;
}

void I�haracter::setDY(float dy)
{
	_dy = dy;
}

float I�haracter::getDY() const
{
	return _dy;
}

void I�haracter::setSpeed(float speed)
{
	_speed = speed;
}

float I�haracter::getSpeed() const
{
	return _speed;
}

void I�haracter::setWidth(unsigned int  width)
{
	_width = width;
}

unsigned int  I�haracter::getWidth() const
{
	return _width;
}

void I�haracter::setHeight(unsigned int  height)
{
	_height = height;
}

unsigned int  I�haracter::getHeight() const
{
	return _height;
}

void I�haracter::setLife(bool life)
{
	_life = life;
}

bool I�haracter::getLife() const
{
	return _life;
}

void I�haracter::setTextureRect(float x, float y, float width, float height)
{
	getSprite().setTextureRect(IntRect((int)x, (int)y, (int)width, (int)height));
}