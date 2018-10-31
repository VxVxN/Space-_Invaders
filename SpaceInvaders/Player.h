#pragma once

#include <iostream>

#include "IÑharacter.h"

using namespace sf;

class Player : private IÑharacter
{
public:
	Player() = delete;
	Player(const String &strFile, float x, float y, float width, float height, float windowsWidth, float windowsHeidht);

	virtual Sprite & getSprite() override final;

	void setPosition(float x, float y);

	virtual unsigned int  getWidth() const override final;
	virtual unsigned int  getHeight() const override final;

	void setSpeedMovement(float speed);

	void draw(RenderWindow &window, float &time);

private:
	enum class StateObject { LEFT, RIGHT };

	float _health;
	StateObject _state;
	float _speed;
	float _windowsWidth, _windowsHeidht;

	void update(float time);

	void control(float time); 

	void setHealth(float health);
	float getHealth() const;

	void setState(StateObject state);
	const StateObject getState() const;
};

