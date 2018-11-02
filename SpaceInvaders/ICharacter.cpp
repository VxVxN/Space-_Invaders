#include "stdafx.h"
#include "ICharacter.h"


Sprite & ICharacter::getSprite()
{
	return sprite;
}

void ICharacter::setFile(const String &strFile)
{
	_nameFileSprite = strFile;
}

const String ICharacter::getFile() const
{
	return _nameFileSprite;
}

void ICharacter::imageLoadFromFile(const String &strFile)
{
	_image.loadFromFile(strFile);
}

Image ICharacter::getImage() const
{
	return _image;
};

Texture & ICharacter::getTexture()
{
	return _texture;
}

void ICharacter::setX(float x)
{
	_x = x;
}

float ICharacter::getX() const
{
	return _x;
}

void ICharacter::setY(float y)
{
	_y = y;
}

float ICharacter::getY() const
{
	return _y;
}

void ICharacter::setDX(float dx)
{
	_dx = dx;
}

float ICharacter::getDX() const
{
	return _dx;
}

void ICharacter::setDY(float dy)
{
	_dy = dy;
}

float ICharacter::getDY() const
{
	return _dy;
}

void ICharacter::setSpeed(float speed)
{
	_speed = speed;
}

float ICharacter::getSpeed() const
{
	return _speed;
}

void ICharacter::setWidth(unsigned int  width)
{
	_width = width;
}

unsigned int  ICharacter::getWidth() const
{
	return _width;
}

void ICharacter::setHeight(unsigned int  height)
{
	_height = height;
}

unsigned int  ICharacter::getHeight() const
{
	return _height;
}

void ICharacter::setLife(bool life)
{
	_life = life;
}

bool ICharacter::getLife() const
{
	return _life;
}

void ICharacter::setTextureRect(float x, float y, float width, float height)
{
	getSprite().setTextureRect(IntRect((int)x, (int)y, (int)width, (int)height));
}