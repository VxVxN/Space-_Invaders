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

	void draw(RenderWindow &window, float &time);

	void moveZigzag(float borderLeft, float borderRight);

private:
	bool _isReadyTurn;
	float _speed;
	unsigned int _windowsWidth, _windowsHeidht;

	RenderWindow * _window;

	void update(float time);
};

