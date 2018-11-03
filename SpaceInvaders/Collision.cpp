#include "stdafx.h"
#include "Collision.h"

#include <iostream>

void Collision::setPlayer(Player & player)
{
	_player = &player;
}

void Collision::setEnemy(std::list<Enemy>& enemies)
{
	_enemies = &enemies;
}

void Collision::update(float time)
{
	for (std::list<Enemy>::iterator itEnemy = _enemies->begin(); itEnemy != _enemies->end(); itEnemy++) {
		for (std::list<CircleShape>::iterator itBullet = _player->_bullets.begin(); itBullet != _player->_bullets.end(); itBullet++) {            // bullet hited enemy
			bool isShotX = ((itEnemy->getX() + itEnemy->getWidth()) > itBullet->getPosition().x) && (itEnemy->getX() < itBullet->getPosition().x);
			bool isShotY = ((itEnemy->getY() + itEnemy->getHeight()) > itBullet->getPosition().y) && (itEnemy->getY() < itBullet->getPosition().y);
			if (isShotX && isShotY) {
				_enemies->erase(itEnemy);
				_player->_bullets.erase(itBullet);
				return;
			}
		}

		bool isHitX = ((itEnemy->getX() + itEnemy->getWidth()) > _player->getX()) && (itEnemy->getX() < (_player->getX() + _player->getWidth()));    // enemy hited player
		bool isHitY = ((itEnemy->getY() + itEnemy->getHeight()) > _player->getY()) && (itEnemy->getY() < (_player->getY() + _player->getWidth()));
		if (isHitX && isHitY) {
			_player->die();
		}
	}
}
