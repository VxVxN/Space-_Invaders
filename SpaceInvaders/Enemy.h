#pragma once

#include "ICharacter.h"
#include "Collision.h"

class Collision;

class Enemy : private ICharacter
{
public:
	friend Collision;

	Enemy() = delete;
	Enemy(const String &strFile, float x, float y, float width, float height, unsigned int windowsWidth, unsigned int windowsHeidht);

	void setPosition(float x, float y);
	void setSpeedMovement(float speed);

	void draw(RenderWindow &window, float &time);

	void moveZigzag(unsigned int borderLeft, unsigned int borderRight);
	void movePointToPoint(float toPointX, float toPointY);

private:
	bool _isReadyTurn;
	float _timeReload;
	unsigned int _windowsWidth, _windowsHeidht;

	std::list<sf::CircleShape> _bullets;
	RenderWindow * _window;

	void update(float time);
	void shoot();
	void die() override final;
};

