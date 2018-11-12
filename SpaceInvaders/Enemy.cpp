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

	_timeReload = 0;

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

void Enemy::moveZigzag(unsigned int borderLeft, unsigned int borderRight)
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

void Enemy::movePointToPoint(float toPointX, float toPointY)
{
	if (getX() < toPointX) {
		if ((toPointX - getX()) <= (toPointY - getY()))
			setDX(getSpeed());
		else 
			setDX(getSpeed() / 0.7f);
	}
	if (getX() > toPointX) {
		if ((toPointX - getX()) >= (toPointY - getY()))
			setDX(-getSpeed());
		else
			setDX(-getSpeed() / 0.7f);
	}
	if (getY() < toPointY) setDY(getSpeed());
	if (getY() > toPointY) setDY(-getSpeed());

	if ((abs(toPointX - getX())) < 1 && (abs(toPointY - getY())) < 1) {
		die();
	}
}


/////////////////////////////private////////////////////////////

void Enemy::update(float time)
{
	if (getLife() == true) {
		setX(getX() + getDX() * time);
		setY(getY() + getDY() * time);

		getSprite().setPosition(getX(), getY());

		_timeReload += time / 1000;
	}
	shoot();
}

void Enemy::shoot()
{
	if (getLife()) {
		if (_timeReload > 2.0f) {
			CircleShape bullet(3.f);
			bullet.setFillColor(sf::Color::Blue);
			bullet.setPosition(getX() + (getWidth() / 2) - 1.5f, getY());
			_bullets.push_back(bullet);
			_timeReload = 0;
		}
	}

	for (auto & bullet : _bullets) {                                                             //move bullet
		bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y + 0.2f);
		_window->draw(bullet);
	}

	for (std::list<CircleShape>::iterator it = _bullets.begin(); it != _bullets.end(); it++) {   // delete bullet
		if (it->getPosition().y > _windowsHeidht) {
			_bullets.erase(it);
			break;
		}
	}
}

void Enemy::die()
{
	getSprite().setColor(sf::Color(255, 255, 255, 0));
	setLife(false);
}
