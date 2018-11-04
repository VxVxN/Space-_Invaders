#pragma once

#include <list>
#include <sstream>

#include "ICharacter.h"
#include "Collision.h"

using namespace sf;

class Collision;

class Player : private ICharacter
{
public:
	friend Collision;

	Player() = delete;
	Player(const String &strFile, float x, float y, float width, float height, unsigned int windowsWidth, unsigned int windowsHeidht);

	void setPosition(float x, float y);

	virtual unsigned int  getWidth() const override final;
	virtual unsigned int  getHeight() const override final;

	void setSpeedMovement(float speed);
	void setSpeedBullet(float speed);
	void setTimeReloadSeconds(float speed);

	void draw(RenderWindow &window, float &time);

	bool isPlayerLost();

private:
	enum class StateObject { LEFT, RIGHT };

	Text _textTopPanel;
	Text _textGameOver;
	Font _font;
	StateObject _state;
	int _score;
	float _health;
	float _speed;
	unsigned int _windowsWidth, _windowsHeidht;
	float _timeReload;
	float _speedBullet;
	float _speedReload;

	std::list<sf::CircleShape> _bullets;
	RenderWindow * _window;

	void update(float time);

	void control(float time); 
	void shoot();
	void updateBullets();
	void die() override final;

	void setHealth(float health);
	float getHealth() const;

	void setState(StateObject state);
	const StateObject getState() const;
};

