#include "stdafx.h"
#include "Player.h"


Player::Player(const String &strFile, float x, float y, float width, float height, unsigned int windowsWidth, unsigned int windowsHeidht) {
	setFile(strFile);
	setWidth((unsigned int)width);
	setHeight((unsigned int)height);

	setSpeed(0.0);
	setSpeedMovement(0.2f);
	setSpeedBullet(0.5f);
	setTimeReloadSeconds(0.5f);

	setLife(true);
	setHealth(100);

	setY(0);
	setX(0);

	setDY(0);
	setDX(0); 

	_windowsWidth = windowsWidth;
	_windowsHeidht = windowsHeidht;

	_timeReload = 0;

	imageLoadFromFile(strFile);
	getTexture().loadFromImage(getImage());

	getSprite().setTexture(getTexture());
	getSprite().setTextureRect(IntRect(x, y + getHeight(), getWidth(), -(float)getHeight()));
}

void Player::setPosition(float x, float y)
{
	setX(x);
	setY(y);
}

unsigned int Player::getWidth() const
{
	return ICharacter::getWidth();
}

unsigned int Player::getHeight() const
{
	return ICharacter::getHeight();
}

void Player::setSpeedMovement(float speed)
{
	_speed = speed;
}

void Player::setSpeedBullet(float speed)
{
	_speedBullet = speed;
}

void Player::setTimeReloadSeconds(float speed)
{
	_speedReload = speed;
}

void Player::draw(RenderWindow & window, float & time)
{
	_window = &window;
	this->update(time);
	window.draw(getSprite());
}


/////////////////////////////private////////////////////////////

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

	updateBullets();

	_timeReload += time / 1000;
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
		if (((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) && !isCollisionRight)) {
			setState(StateObject::RIGHT);
			setSpeed(_speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			shoot();
		}
	}
}

void Player::shoot()
{
	if (_timeReload > _speedReload) {
		CircleShape bullet(3.f);
		bullet.setFillColor(sf::Color::Red);
		bullet.setPosition(getX() + (getWidth() / 2) - 1.5f, getY());
		_bullets.push_back(bullet);
		_timeReload = 0;
	}
}

void Player::updateBullets()
{
	for (auto & bullet : _bullets) {   //move bullet
		bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - _speedBullet);
		_window->draw(bullet);
	}

	for (std::list<CircleShape>::iterator it = _bullets.begin(); it != _bullets.end(); it++) {   // delete bullet
		if (it->getPosition().y < 0) {
			_bullets.erase(it);
			break;
		}
	}
}

void Player::die()
{
	getSprite().setColor(sf::Color::Red);
	setLife(false);
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