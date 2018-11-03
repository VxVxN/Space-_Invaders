#pragma once

#include <list>

#include "Player.h"
#include "Enemy.h"

class Enemy;
class Player;

class Collision
{
public:
	Collision() = default;

	void setPlayer(Player & player);
	void setEnemy(std::list<Enemy>& enemies);

	void update(float time);

private:
	Player * _player;
	std::list<Enemy>* _enemies;
};

