#include "stdafx.h"
#include "Player.h"


Player::Player(const String &strFile, float x, float y, float width, float height, float windowsWidth, float windowsHeidht) {
	setFile(strFile);
	setWidth((unsigned int)width);
	setHeight((unsigned int)height);

	setSpeed(0.0);
	_speed = 0.1f;

	setLife(true);
	setHealth(100);

	setY(0);
	setX(0);

	setDY(0);
	setDX(0); 

	_windowsWidth = windowsWidth;
	_windowsHeidht = windowsHeidht;

	imageLoadFromFile(strFile);
	getTexture().loadFromImage(getImage());

	getSprite().setTexture(getTexture());
	getSprite().setTextureRect(IntRect(x, y + getHeight(), getWidth(), -(float)getHeight()));
}

Sprite& Player::getSprite()
{
	return sprite;
}

void Player::setPosition(float x, float y)
{
	setX(x);
	setY(y);
}

unsigned int Player::getWidth() const
{
	return IÑharacter::getWidth();
}

unsigned int Player::getHeight() const
{
	return IÑharacter::getHeight();
}

void Player::setSpeedMovement(float speed)
{
	_speed = speed;
}

void Player::draw(RenderWindow & window, float & time)
{
	this->update(time);
	window.draw(getSprite());
}


/////////////private//////////

void Player::update(float time)
{
	control(time);

	switch (getState())
	{
	case StateObject::RIGHT: setDX(getSpeed());	 break;
	case StateObject::LEFT:	 setDX(-getSpeed()); break;
	}

	setX(getX() + getDX() * time);

	setSpeed(0);
	getSprite().setPosition(getX(), getY());

	if (getHealth() <= 0) {
		setLife(false);
	}
}

void Player::control(float time)
{
	if (getLife()) {
		bool isCollisionLeft  = getX() < 0;
		bool isCollisionRight = (getX() + getWidth()) > _windowsWidth;
		if (((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) && !isCollisionLeft)) {
			setState(StateObject::LEFT);
			setSpeed(_speed);
		}
		else if (((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) && !isCollisionRight)) {
			setState(StateObject::RIGHT);
			setSpeed(_speed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space)) {
			//shoot();
		}
	}
}

void Player::setHealth(float health)
{
	_health = health;
}

float Player::getHealth() const
{
	return _health;
}

void Player::setState(StateObject state)
{
	_state = state;
}

const Player::StateObject Player::getState() const
{
	return _state;
}