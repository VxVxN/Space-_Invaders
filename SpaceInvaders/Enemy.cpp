#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(const String &strFile, float x, float y, float width, float height, unsigned int windowsWidth, unsigned int windowsHeidht) {
	setFile(strFile);
	setWidth((unsigned int)width);
	setHeight((unsigned int)height);

	setSpeed(0.05f);

	_isReadyTurn = true;

	setLife(true);

	setY(0);
	setX(0);

	setDY(0);
	setDX(0);

	_windowsWidth = windowsWidth;
	_windowsHeidht = windowsHeidht;

	imageLoadFromFile(strFile);
	getTexture().loadFromImage(getImage());

	getSprite().setTexture(getTexture());
	getSprite().setTextureRect(IntRect((int)x, (int)y + getHeight(), getWidth(), int(-(float)getHeight())));
}

void Enemy::setPosition(float x, float y)
{
	setX(x);
	setY(y);
}

void Enemy::draw(RenderWindow & window, float & time)
{
	_window = &window;
	this->update(time);
	window.draw(getSprite());
}

void Enemy::moveZigzag(float borderLeft, float borderRight)
{
	setDY(getSpeed());
	if (getX() < borderRight && _isReadyTurn) {
		setDX(getSpeed());
	}
	else {
		_isReadyTurn = false;
	}
	if (getX() > borderLeft && !_isReadyTurn) {
		setDX(-getSpeed());
	}
	else {
		_isReadyTurn = true;
	}
}


/////////////////////////////private////////////////////////////

void Enemy::update(float time)
{
	setX(getX() + getDX() * time);
	setY(getY() + getDY() * time);

	getSprite().setPosition(getX(), getY());
}