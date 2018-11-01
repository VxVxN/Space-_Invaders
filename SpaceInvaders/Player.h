#pragma once

#include <list>

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
	void setSpeedBullet(float speed);
	void setTimeReloadSeconds(float speed);

	void draw(RenderWindow &window, float &time);

private:
	enum class StateObject { LEFT, RIGHT };

	StateObject _state;
	float _health;
	float _speed;
	float _windowsWidth, _windowsHeidht;
	float _timeReload;
	float _speedBullet;
	float _speedReload;

	std::list<sf::CircleShape> _listBullet;
	RenderWindow * _window;

	void update(float time);

	void control(float time); 
	void shoot();
	void updateBullets();

	void setHealth(float health);
	float getHealth() const;

	void setState(StateObject state);
	const StateObject getState() const;
};

